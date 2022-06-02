//  main.cpp
//  ADSA3
//
//  Created by Nishika Agarwal on 23/01/22.
//

#include <iostream>

using namespace std;

struct node {
    struct node *left;
    char data;
    int height;
    struct node *right;

};

class AVL
{
private:
    
public:
    struct node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(struct node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height;
            }
            else if(n->left && n->right == NULL){
                return n->left->height;
            }
            else if (n->left== NULL && n->right ){
                return -n->right->height;
            }
            return 0;
    }

    struct node * llrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    struct node * rrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    struct node * rlrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp;
        
        return tp2;
    }

    struct node * lrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp;
        
        return tp2;
    }

    struct node* insert(struct node *r,char data){
        
        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1;
            return r;
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }

        return r;

        }

    void display(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;
        }
        display(this->root,1);
    }

    void display(struct node *v, int level){
        
        int i;
            if (v!=NULL)
            {
                display(v->right, level + 1);
                printf("\n");
                if (v == root)
                cout<<"Root -> ";
                for (i = 0; i < level && v != root; i++)
                    cout<<"        ";
                cout<<v->data;
                display(v->left, level + 1);
            }
    }
 
    struct node * deleteNode(struct node *p,char data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        
        struct node *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data > data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

        
        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;
    }

    ~AVL(){

    }
};


int main(){

    AVL b;
    int c;
    char x;

    do{
        cout<<"\n1.Display";
        cout<<"\n2.Insert";
        cout<<"\n3.Delete\n";
        cout<<"\n0.Exit\n";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            b.display();
            // to print the tree in level order
            break;
                  
        case 2:
            cout<<"\nEnter element. ";
            cin>>x;
            b.root = b.insert(b.root,x);
            break;
        
        case 3:
            cout<<"\nEnter element to be deleted ";
            cin>>x;
            b.root = b.deleteNode(b.root,x);
            break;
            
        case 0:
            break;
        }

     } while(c!=0);
  
}
