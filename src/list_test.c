#include "list.h"

void print_doors_list(struct node *root);
int len_of_list(struct node *root);

int main() {
    struct door door_1 = {0, 1};
    struct node *root = init(&door_1);

    printf("\nДверь для инициализации списка: ");
    printf("%d, %d\n", door_1.id, door_1.status);

    printf("Результат инициализации: ");
    if (root != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    //вставляем новые двери

    struct door door2 = {1, 1};
    struct node *added_elem = add_door(root, &door2);

    printf("\n\nПечатаем двери: ");
    print_doors_list(root);

    printf("\nРезультат вставки второй двери: ");
    if (added_elem != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    // поиск по айди

    int door_id_1 = 1;
    struct node *node_with_door_id_1 = find_door(door_id_1, root);

    printf("\n\nПоиск двери с id %d: ", door_id_1);

    if (node_with_door_id_1 != NULL) {
        printf("SUCCESS\nДверь с id=%d найдена, status=%d\n", door_id_1, node_with_door_id_1->data.status);
    } else {
        printf("FAIL\nДверь с id = %d не найдена\n", door_id_1);
    }

    // удаляем елемент

    printf("\nУдаление двери: ");
    int start_len = len_of_list(root);

    struct node *node_ptr = root;

    root = remove_door(node_ptr, root);
    print_doors_list(root);
    int finish_len = len_of_list(root);

    if (start_len - 1 == finish_len) {
        printf("\nРезультат удаления двери: SUCCESS\n\n");
    } else {
        printf("\nРезультат удаления двери: FAIL\n\n");
    }

    //удаляем фсе

    destroy(root);
    printf("Результат удаления списка дверей: SUCCESS\n\n");

    return 0;
}

//выводим список
void print_doors_list(struct node *root) {
    struct node *ptr = root;
    while (1) {
        if (ptr == NULL) break;

        printf("%d, %d; ", ptr->data.id, ptr->data.status);

        ptr = ptr->next;
    }
}

//определяем длину
int len_of_list(struct node *root) {
    int count = 0;
    struct node *ptr = root;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}