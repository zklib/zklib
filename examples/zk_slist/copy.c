#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zk/zklib.h"

void print_list(void *data, __attribute__((__unused__)) void *user_data)
{
	printf("data: %s\n", (char *)data);
}

int main()
{
	zk_slist_t *list = NULL, *list_cp = NULL;

	list = zk_slist_append(list, strdup("This"));
	list = zk_slist_append(list, strdup("list"));
	list = zk_slist_append(list, strdup("will"));
	list = zk_slist_append(list, strdup("be"));
	list = zk_slist_append(list, strdup("shallow"));
	list = zk_slist_append(list, strdup("copied."));

	// creates a shallow copy of list
	list_cp = zk_slist_copy(list);

	// print list_cp
	zk_slist_foreach(list_cp, print_list, NULL);

	// As this is a shallow copy if one of the lists is freed the other list loses its reference to data.
	zk_slist_free_full(&list, free);
	// Note that from now on all list_cp nodes have dangling pointers to data
	zk_slist_free(&list_cp);

	return 0;
}
