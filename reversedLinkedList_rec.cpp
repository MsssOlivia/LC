LinkedListNode* reverse_recursive(
    LinkedListNode* head) {
  // no need to reverse if head is nullptr 
  // or there is only 1 node.
  // (head->next == nullptr is base case for recursion)
  if (head == nullptr || 
      head->next == nullptr) {
    return head;
  }

  LinkedListNode* reversed_list = 
    reverse_recursive(head->next);

  head->next->next=head;
  head->next = nullptr;
  return reversed_list;
}

int main(int argc, char* argv[]) {
  vector<int> v1 = {1, 2, 3, 4 , 5};
  LinkedListNode* list_head = LinkedList::create_linked_list(v1);

  // Iterative Reverse Test
  printf("Original: ");
  LinkedList::display(list_head);
  list_head = reverse_recursive(list_head);
  printf("After Reverse (Iterative):");
  LinkedList::display(list_head);

  vector<int> v2 = {5, 4, 3, 2, 1};
  LinkedListNode* expected_list_head = LinkedList::create_linked_list(v2);
  assert(LinkedList::is_equal(list_head, expected_list_head));
}
