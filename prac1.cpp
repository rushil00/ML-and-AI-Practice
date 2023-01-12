#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertEndNode(ListNode* List , int n){
            ListNode* newNode = new ListNode(n);
                ListNode *tempNode = new ListNode;
                tempNode = List;
                while(tempNode->next != NULL){
                    tempNode = tempNode->next;
                }
                tempNode->next = newNode;
    }
ListNode* createFromArray(int arr[] , int size){ //takes an integer array and its size;
    ListNode* ll;
    for (int i = 0 ; i < size ; i++){
        insertEndNode(ll , arr[i]);
    }    
    return ll;
}
void display(ListNode* Head){
        ListNode* temp = Head;
        while(temp != NULL){
            cout<<temp->val<<endl;
            temp = temp->next;
        }
    }
class Solution {
    public:
    int ListLen(ListNode* head){
        int len = 1;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            ++len;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_l1 = ListLen(l1);
        int len_l2 = ListLen(l2);
        ListNode* l1Temp = l1;
        ListNode* l2Temp = l2;
        ListNode* resultListHead = new ListNode;
        ListNode* resultListTemp = new ListNode;
        resultListTemp = resultListHead;
        int num;
        if(len_l1 <= len_l2){
            num = len_l2;
        }
        else if(len_l2 < len_l1){
            num = len_l1;
        }
        int buffer_num = 0;
        int n;
        for(int i = 0 ; i < num && resultListTemp != NULL ; ++i)
        {
            //adding zeroes if one of the lists is exhausted.
            if(l1Temp == NULL){
                n = l2Temp->val+buffer_num;
                resultListTemp->val = (n)%10;
                l2Temp = l2Temp->next;
            }
            else if(l2Temp == NULL){
                n = l1Temp->val+buffer_num;
                resultListTemp->val = (n)%10;
                l1Temp = l1Temp->next;
            }
            else
            {
                n = l2Temp->val+l1Temp->val+buffer_num;
                resultListTemp->val = (n)%10;
                l1Temp = l1Temp->next;
                l2Temp = l2Temp->next;
            }
            resultListTemp = resultListTemp->next;


            if(n >= 10){
                buffer_num = 1;

            }
            else 
            {
                buffer_num = 0;
            }
        }
        display(resultListHead);
        return resultListHead;
    }

};
int main(){
    int a[3] = {2,4,3};
    int a2[3] = {5,6,4};
    ListNode* l1 = createFromArray(a,3);
    ListNode* l2 = createFromArray(a2,3);
    Solution S3;
    S3.addTwoNumbers(l1,l2);
    return 0;
}