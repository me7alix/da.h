#define DA_RUNTIME_CHECKS
#include <stdio.h>
#include "da.h"

typedef struct {
	char *items;
	size_t count;
	size_t capacity;
} StringBuilder;

int main(void) {
	da(int) nums = {0};

	for (size_t i = 0; i < 10; i++) {
		da_append(&nums, i);
	}
	
	da_remove_unordered(&nums, 8);

	for (size_t i = 0; i < nums.count; i++) {
		printf("%i ", da_get(&nums, i));
	}

	printf("\n");
	da_resize(&nums, 3);

	printf("cap: %zu\n", nums.capacity);

	for (size_t i = 0; i < 3; i++) {
		da_append(&nums, i);
	}

	da_insert(&nums, 1, -1);

	for (size_t i = 0; i < nums.count; i++) {
		printf("%i ", da_get(&nums, i));
	}

	printf("\n");
	da_free(&nums);

	StringBuilder sb = {0};

	da_append(&sb, 'h');
	da_append(&sb, 'e');
	da_append(&sb, 'l');
	da_append(&sb, 'l');
	da_append(&sb, 'o');
	da_append(&sb, '\0');

	da_remove_ordered(&sb, 1);
	printf("sb: %s\n", sb.items);

	da_remove_ordered(&sb, 8);

	da_free(&sb);
	return 0;
}
