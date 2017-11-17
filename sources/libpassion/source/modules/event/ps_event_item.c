#include <stdlib.h>
#include <string.h>

#include <utils/ps_check.h>

#include <modules/event/ps_event_item.h>

enum ps_status ps_events_list_clear(struct ps_event_item **list)
{
        struct ps_event_item *head = *list;
        while (head) {
                struct ps_event_item *next = head->next;
                free(head);
                head = next;
        }

        *list = NULL;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_events_list_push(struct ps_event_item **list,
        struct ps_event_data *event
)
{
        PS_CHECK(list && event, PS_STATUS_INVALID_ARGUMENT);

        struct ps_event_item *head = *list;

        struct ps_event_item *prev = NULL;
        while (head) {
                prev = head;
                head = head->next;
        }

        head = malloc(sizeof(struct ps_event_item));
        memcpy(head, event, sizeof(struct ps_event_data));
        head->next = NULL;

        if (prev)
                prev->next = head;

        if (!*list)
                *list = head;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_events_list_pop(struct ps_event_item **list,
        struct ps_event_data *event
)
{
        PS_CHECK(list && event, PS_STATUS_INVALID_ARGUMENT);        

        struct ps_event_item *head = *list;
        memcpy(event, &head->data, sizeof(struct ps_event_data));

        *list = head->next;
        free(head);

        return PS_STATUS_SUCCESS;
}