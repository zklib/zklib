#include <stdio.h>
#include <stdlib.h>

#include "zk/zklib.h"

void print_list(void *data, __attribute__((__unused__)) void *user_data)
{
	printf("data: %s\n", (char *)data);
}

int main()
{
	zk_slist *list = NULL;

	list = zk_push_back(list, "1");
	list = zk_push_back(list, "2");
	list = zk_push_back(list, "4");

	// insert "0" as the first element of the list
	list = zk_slist_insert(list, "0", 1);
	// insert "3" as the fourth element of the list
	list = zk_slist_insert(list, "3", 4);
	// as position is greater than the number of node the list has "5" will be insert at end of the list.
	list = zk_slist_insert(list, "5", 100);
	// as position is O, node is inserted at the end of the list.
	list = zk_slist_insert(list, "6", 0);

	// calls zk_for_each() to print each node`s data of the list
	zk_for_each(list, print_list, NULL);

	// frees list
	zk_free(&list, NULL);

	return 0;
}
