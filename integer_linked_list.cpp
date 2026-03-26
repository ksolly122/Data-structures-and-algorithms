#include <stdio.h>

struct int_list_item {
    int number;  // 4 bytes
    int_list_item *next;  // 8 bytes
};

struct int_list {
    int_list_item *first_node = 0;
};

void add_number(int_list &list, int number) {
    int_list_item *new_node = new int_list_item;
    new_node->number = number;
    new_node->next = list.first_node;
    list.first_node = new_node;
}

int pop_number(int_list &list) {
    if (list.first_node) {
        int popped_number = list.first_node->number;
        int_list_item *temp = list.first_node;
        list.first_node = list.first_node->next;
        delete temp;
        return popped_number;
    }
    return -1;  // Return -1 if list is empty
}

void remove_by_index(int_list &list, int index) {
    int_list_item *current = list.first_node;
    int_list_item *prev = nullptr;
    int current_index = 0;

    while (current && current_index != index) {
        prev = current;
        current = current->next;
        current_index++;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            list.first_node = current->next;
        }
        delete current;
    }
}

bool is_number_in_list(int_list &list, int number) {
    int_list_item *current = list.first_node;
    while (current) {
        if (current->number == number) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    int_list test_list;
    add_number(test_list, 240);
    add_number(test_list, 310);
    add_number(test_list, 435);

    // Let's print them out!
    for (int_list_item *place = test_list.first_node; place; place = place->next) {
        printf("%d (stored at address %p)\n", place->number, &place->number);
    }

    printf("Pop item: %d\n", pop_number(test_list));

    remove_by_index(test_list, 1); // Remove item at index 1

    printf("Is 240 in list? %s\n", is_number_in_list(test_list, 240) ? "Yes" : "No");

    return 0;
}
