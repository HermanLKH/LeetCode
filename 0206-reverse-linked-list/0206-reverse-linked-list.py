# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        
        currNode = head.next
        prevNode = head
        nextNode = currNode.next
        head.next = None

        while currNode is not None:
            currNode.next = prevNode
            prevNode = currNode
            currNode = nextNode

            if nextNode is not None:
                nextNode = currNode.next
            else:
                nextNode = None

        return prevNode

