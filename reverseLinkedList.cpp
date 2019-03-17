LinkedListNode* reverse_iterative(
    LinkedListNode* head) {
  // no need to reverse if head is nullptr 
  // or there is only 1 node.
  if (head == nullptr || 
      head->next == nullptr) {
    return head;
  }

  LinkedListNode* list_to_do = head->next;

  LinkedListNode* reversed_list = head;
  reversed_list->next = nullptr;

  while (list_to_do != nullptr) {
    LinkedListNode* temp = list_to_do;
    list_to_do = list_to_do->next;

    temp->next = reversed_list;
    reversed_list = temp;
  }

  return reversed_list;
}

int main(int argc, char* argv[]) {
  vector<int> v1 = {1, 2, 3, 4 , 5};
  LinkedListNode* list_head = LinkedList::create_linked_list(v1);

  // Iterative Reverse Test
  printf("Original: ");
  LinkedList::display(list_head);
  list_head = reverse_iterative(list_head);
  printf("After Reverse (Iterative):");
  LinkedList::display(list_head);

  vector<int> v2 = {5, 4, 3, 2, 1};
  LinkedListNode* expected_list_head = LinkedList::create_linked_list(v2);
  assert(LinkedList::is_equal(list_head, expected_list_head));
}
