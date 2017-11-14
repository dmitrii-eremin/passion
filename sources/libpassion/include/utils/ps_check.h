#ifndef LIBPASSION_INCLUDE_UTILS_PS_CHECK_H_
#define LIBPASSION_INCLUDE_UTILS_PS_CHECK_H_

#define PS_SAFE_CALL(X) if (X) (X)
#define PS_CHECK(X, S) if (!(X)) return S;

#endif