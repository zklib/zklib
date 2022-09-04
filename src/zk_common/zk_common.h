#ifndef ZK_COMMON_H
#define ZK_COMMON_H

#define ZK_UNUSED(x) (void)(x)

typedef int (*zk_compare_t)(const void *const data, const void *const user_data);

typedef void *(*zk_copy_data_t)(const void *const data, void *user_data);

typedef void (*zk_destructor_t)(void *data);

typedef void (*zk_for_each_func)(void *data, void *user_data);

typedef enum zk_status {
	ZK_OK = 0,
	ZK_ERROR_ALLOC = 1,
	ZK_INVALID_ARGUMENT = 2,
} zk_status;

#endif
