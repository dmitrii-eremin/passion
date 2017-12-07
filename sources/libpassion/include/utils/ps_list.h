#ifndef LIBPASSION_INCLUDE_UTILS_PS_LIST_H_
#define LIBPASSION_INCLUDE_UTILS_PS_LIST_H_
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "ps_check.h"
#include "ps_status.h"

#define PS_DEFINE_LIST(NAME, ITEM, DATA, MODIFIER) \
\
struct ITEM { \
        DATA data; \
        struct ITEM *next; \
}; \
\
MODIFIER enum ps_status NAME##_clear( \
        struct ITEM **list \
); \
\
MODIFIER enum ps_status NAME##_push_back( \
        struct ITEM **list, \
        DATA *element \
); \
\
MODIFIER enum ps_status NAME##_pop_front( \
        struct ITEM **list, \
        DATA *element \
); \
\
MODIFIER enum ps_status NAME##_pop_back( \
        struct ITEM **list, \
        DATA *element \
); \
\
MODIFIER enum ps_status NAME##_remove( \
        struct ITEM **list, \
        DATA *element \
); \
\
MODIFIER enum ps_status NAME##_find(\
        struct ITEM **list, \
        DATA **element, \
        void *userdata, \
        bool (*comparator)(DATA *item, void *userdata) \
); \
\
MODIFIER enum ps_status NAME##_get_last(\
        struct ITEM **list, \
        DATA **element \
);


#define PS_DECLARE_LIST(NAME, ITEM, DATA) \
\
enum ps_status NAME##_clear(struct ITEM **list) \
{ \
        struct ITEM *head = *list; \
        while (head) { \
                struct ITEM *next = head->next; \
                free(head); \
                head = next; \
        } \
\
        *list = NULL; \
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_push_front(struct ITEM **list, \
        DATA *element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        struct ITEM *head = *list; \
\
        struct ITEM *new_head = malloc(sizeof(struct ITEM)); \
        memcpy(new_head, element, sizeof(DATA)); \
        new_head->next = head; \
\
        *list = new_head; \
\
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_push_back(struct ITEM **list, \
        DATA *element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        struct ITEM *head = *list; \
\
        struct ITEM *prev = NULL; \
        while (head) { \
                prev = head; \
                head = head->next; \
        } \
\
        head = malloc(sizeof(struct ITEM)); \
        memcpy(head, element, sizeof(DATA)); \
        head->next = NULL; \
\
        if (prev) \
                prev->next = head; \
\
        if (!*list) \
                *list = head; \
\
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_pop_front(struct ITEM **list, \
        DATA *element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        bool last_one_item = (*list)->next == NULL; \
\
        struct ITEM *head = *list; \
        memcpy(element, &head->data, sizeof(DATA)); \
\
        *list = head->next; \
        free(head); \
\
        if (last_one_item) \
                *list = NULL; \
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_pop_back(struct ITEM **list, \
        DATA *element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        bool last_one_item = (*list)->next == NULL; \
\
        struct ITEM *prev = NULL; \
        struct ITEM *head = *list; \
        while (head->next) { \
                prev = head; \
                head = head->next; \
        } \
\
        if (head) { \
                memcpy(element, &head->data, sizeof(DATA)); \
                free(head); \
        } \
\
        if (prev) \
                prev->next = NULL; \
        if (last_one_item) \
                *list = NULL; \
\
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_remove(struct ITEM **list, \
        DATA *element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        struct ITEM *prev = NULL; \
        struct ITEM *head = *list; \
        while (head) { \
                if (&head->data == element)  \
                        break; \
                prev = head; \
                head = head->next; \
        } \
        if (!head) \
                return PS_STATUS_SUCCESS; \
\
        if (!prev) { \
                *list = head->next; \
                free(head); \
        } else { \
                prev->next = head->next; \
                free(head); \
        } \
\
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_find( \
        struct ITEM **list, \
        DATA **element, \
        void *userdata, \
        bool (*comparator)(DATA *item, void *userdata) \
) \
{ \
        PS_CHECK(list && comparator && element, PS_STATUS_INVALID_ARGUMENT); \
\
        *element = NULL; \
        struct ITEM *head = *list; \
        do { \
                if (!head) \
                        break; \
                bool res = comparator(&head->data, userdata); \
                if (res) { \
                        *element = &head->data; \
                        break; \
                }\
                head = head->next; \
        } while (head); \
\
        return PS_STATUS_SUCCESS; \
} \
\
enum ps_status NAME##_get_last( \
        struct ITEM **list, \
        DATA **element \
) \
{ \
        PS_CHECK(list && element, PS_STATUS_INVALID_ARGUMENT); \
\
        *element = NULL; \
        struct ITEM *head = *list; \
        do { \
                if (!head) \
                        break; \
                *element = &head->data; \
                head = head->next; \
        } while (head); \
\
        return PS_STATUS_SUCCESS; \
} \

#endif