// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
      struct compr{
           bool operator()(Node* a, Node* b){
                return a->data>b->data;
            }
        } ;
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *lists[], int K)
    {
           // Your code here
        //int n = lists.size();
        priority_queue<Node*, vector<Node*>, compr>minHeap;
        Node* head= new Node(0);
        Node* temp = head;
        
        for(int i=0; i<K; i++){
            if(lists[i]!=NULL)
              minHeap.push(lists[i]);
        }
        
        
        while(!minHeap.empty()){
            
            Node* smallest = minHeap.top();
            minHeap.pop();
            temp->next = smallest;
            temp=temp->next;
            
            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return head->next;
        
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends