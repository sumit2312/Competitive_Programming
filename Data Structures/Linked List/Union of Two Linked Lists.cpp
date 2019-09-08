/*This is a function problem.You only need to complete the function given below*/
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* makeUnion(struct node* head1, struct node* head2)
{
    vector<int> v;
    set<int> s;
    node* t1=head1;
    while(t1!=NULL){
        s.insert(t1->data);
        t1 = t1->next;
    }
    node* t2=head2;
    while(t2!=NULL){
        s.insert(t2->data);
        t2 = t2->next;
    }
    for(auto x:s){
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    node* res=NULL;
    for(auto x:v){
        node* t=new node();
        t->data=x;
        if(res==NULL){
            res=t;
        }else{
            t->next=res;
            res=t;
        }
    }
    return res;
}
