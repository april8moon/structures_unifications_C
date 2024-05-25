#include "list.h"

// Функция инициализации структуры
struct node* init(struct door* door) {
    struct node* my_node = (struct node*)malloc(sizeof(struct node));

    if (my_node != NULL) {
        my_node->data.id = door->id;
        my_node->data.status = door->status;
        my_node->next = NULL;
    }

    return my_node;
}

// Функция вставки нового элемента
struct node* add_door(struct node* elem, struct door* door) {
    struct node* my_node = NULL;

    if (elem != NULL) {
        my_node = (struct node*)malloc(sizeof(struct node));

        if (my_node != NULL) {
            my_node->data.id = door->id;
            my_node->data.status = door->status;

            my_node->next = elem->next;
            elem->next = my_node;
        }
    }

    return my_node;
}

// Функция поиска двери в списке по её id
struct node* find_door(int door_id, struct node* root) {
    struct node* p_node = root;

    while (p_node != NULL) {
        if (p_node->data.id == door_id) {
            break;
        }

        p_node = p_node->next;
    }

    return p_node;
}

// Функция удаления элемента списка
struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p_node = root;

    if (elem == root) {
        p_node = root->next;
        free(elem);
    } else {
        while (p_node->next != elem) {
            p_node = p_node->next;
        }
        p_node->next = elem->next;
        free(elem);
        p_node = root;
    }

    return p_node;
}

// Функция освобождение памяти
void destroy(struct node* root) {
    struct node* p_node = root;

    while (p_node != NULL) {
        struct node* deleted_node = p_node;

        p_node = p_node->next;

        free(deleted_node);
    }
}