#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *next;
}*last;
 
class circular_llist
{
    public:
    	void reverse();
    	void search(int ele);
        void add_end(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void display_list();
		circular_llist()
        {
            last = NULL;           
        }
};
 
int main()
{
    int choice, element, position,ele;
    circular_llist cl;
    do{
    	cout<<"\nMain Menu";     
        cout<<"\n1.Add at end";
        cout<<"\n2.Add at beginning";
        cout<<"\n3.Add after";
        cout<<"\n4.Delete";
        cout<<"\n5.search";
    	cout<<"\n6.reverse";
    	cout<<"\n7.display";
        cout<<"\nEnter your choice : ";
        cin>>choice;

		switch(choice)
        {
			case 1:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_end(element);
				cout<<endl;
				break;
			case 2:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_begin(element);
				cout<<endl;
				break;
			case 3:
				cout<<"\nEnter the element: ";
				cin>>element;
				cout<<"\nInsert element after position: ";
				cin>>position;
				cl.add_after(element, position);
				cout<<endl;
				break;
			case 4:
				if (last == NULL)
				{
					cout<<"\nList is empty, nothing to delete";
					break;
				}
				cout<<"\nEnter the element for deletion: ";
				cin>>element;
				cl.delete_element(element);
				cout<<endl;
				break;
			case 5:cout<<"Enter the elemeent to be searched ";
						cin>>ele;
					cl.search(ele);         
					break;
			
			case 6:   cl.reverse();
						break;
			case 7:		cl.display_list();
				break;
        }
    }while(choice!=6);
}

void circular_llist::add_end(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}

void circular_llist:: reverse()
{
    struct node *p, *q, *r;
 
    p = q = r = last->next;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != last)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    last = q;
}
 
void circular_llist:: search(int ele)
{
	int flag=0;
	int count=0;
	struct node *t;
	t=last->next;
	while(t->next!=last)
	{
		++count;
		if(t->info==ele)
		{	
			flag=1;
			cout<<"Element found at position "<<count;
			break;
		}
		t=t->next;
	}
	if(flag==0)
	cout<<"Element not found ";
}
 
void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}
 
void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp, *s;
    s = last->next;

	for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }

	temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;

	if (s == last)
    { 
        last=temp;
    }
}
 
void circular_llist::delete_element(int value)
{
    struct node *temp, *s;
    s = last->next;
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value)  
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }

	while (s->next != last)
    {
        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }

	if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 
void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;

	while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}
