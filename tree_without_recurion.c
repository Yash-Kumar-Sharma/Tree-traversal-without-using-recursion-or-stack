/*********** Tree traversal without using recursion or stack  ************/
/**** 		Author	: Yash Kumar Sharma 		******************/
/****		Email	: sharma.yash914@gmail.com	******************/
/**** It will give correct output till the given height ******************/ 

#include<stdio.h>
#include<stdlib.h>
#define MAX 100					//Array size
//structure for a node of tree

struct node
{
       struct node *rtree;
       int data;
       struct node *ltree;
};

//all function prototype that are used in program

void insert(struct node **,int);
int search(int);
void inorder_making();
void traverse_result();
int power(int,int);
void preorder_making();
void postorder_making();

//Global variables

struct node *parent;

int result[MAX],tree_nodes[MAX],traverse[MAX];
int hh=1,right,height,hgt;

//Main function 

int main()
{
    int i,item,choice;
    printf("\n Enter the height (level+1, root at level 0) of tree : ");
    scanf("%d",&hgt);
    height=power(2,hgt+1);
    for(i=0;i<height;i++)		//Array is initialized according to the given maximum possible height of the tree
    tree_nodes[i]=-1;
    
    struct node *p;
    p=NULL;
    do
    {
	system("clear");
	printf("\n--------BST--------\n");
        printf("\n1. insert a node in tree \n");
        printf("\n2. InOrder Traverse \n");
        printf("\n3. PreOrder Traverse \n");
        printf("\n4. PostOrder Traverse \n");
        printf("\n5. Exit \n");
        printf("\n Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
                      case 1:
                           printf("\nEnter a node in tree : ");
                           scanf("%d",&item);
                           insert(&p,item);
                           printf("\n Successfully Entered \n");
                           break;
                      case 2:
                           printf("\n");
                           inorder_making();
                           traverse_result();
                           break;
                      case 3:
                           printf("\n");
                           preorder_making();
                           traverse_result();
                           break;
                      case 4:
                           printf("\n");
                           postorder_making();
                           traverse_result();
                           break;
                      
        }
    }while(choice!=5);
    return 0;
}

//------------------------End---------------

//function to insert a single node

void insert(struct node **n,int data_item)
{
     int i,pos;
     if((*n)==NULL)
     {
                   if(hh==1)
                   tree_nodes[hh++]=data_item;
                   else
                   {
                       pos=search(parent->data);
                       if(right==0)
                       pos=pos*2;
                       else
                       pos=pos*2+1;
                       tree_nodes[pos]=data_item;
                   }
                (*n)=(struct node*)malloc(sizeof(struct node));     
                (*n)->ltree=NULL;
                (*n)->data=data_item;
                (*n)->rtree=NULL;
                return;
     }
     else
     {
         if(data_item>=(*n)->data)
         {
             parent=(*n);
             right=1;   
             insert(&((*n)->rtree),data_item);
         }      //insert in right subtree
         else
         {
             parent=(*n);
             right=0;
             insert(&((*n)->ltree),data_item);
         }	//insert in left subtree
         return;
     }
}

//-------------------------End---------------

//function to serach the position of a node in tree

int search(int data)
{
    int i;
    for(i=0;i<height;i++)
    {
                         if(tree_nodes[i]==data)
                         break;
    }
    return i;
}
//------------------End----------------

//function to making inorder

void inorder_making()
{
     int h=hgt;
    
    int l=1,j=h+1,k=0,m=1,n,i,low,high;
    
    for(i=0;i<power(2,j)-1;i++)
    result[i]=0;
    
    for(h=j;h>j-4;h--)
    {
                    low=power(2,h-1);
                    high=power(2,h);
                    for(i=low;i<high;i++)
                    {
                                                     if(h==j)
                                                     {
                                                             result[k]=i;
                                                             result[k+1]=i/2;
                                                             result[k+2]=i+1;
                                                             k=k+4;
                                                     }
                                                     else
                                                     {
                                                         result[k]=i/2;
                                                         m=m+2;
                                                         k=n*m-1;
                                                     }
                                                     i++;
                    }
                    k=4*l-1;
                    l=l*2;
                    n=k+1;
                    m=1;
    }                       
}

//------------------------END----------------------

//function to making preorder

void preorder_making()
{
     int h=hgt;
    int j=h+1,k=h-1,i,low,high,m;
    int length;
    length=power(2,j+1);
    for(i=0;i<=length;i++)
    result[i]=0;
    
    for(h=j;h>0;h--)
    {
                    low=power(2,h-1);
                    high=power(2,h);
                    if(h==j)
                    for(i=low;i<high;i++)
                    {
                                         result[k]=i/2;
                                         result[k+1]=i;
                                         result[k+2]=i+1;
                                         k=k+j;
                                         i++;
                    }
                    else
                    for(m=0;m<=length;m++)
                    {
                                          if(result[m]!=0)
                                          {
                                                          if(result[m]%2==0)
                                                          result[m-1]=result[m]/2;
                                                          while(result[m]!=0)
                                                          m++;
                                          }
                    }
    }
    j=0;
    for(i=0;i<=length;i++)
    {
                          if(result[i]!=0)
                          {
                                          result[j]=result[i];
                                          j++;
                          }
    }
}

//----------------------END-------------------

//function to making postorder

void postorder_making()
{
    int h=hgt;
    int j=h+1,k=0,i,low,high,m;
    int length;
    length=power(2,j+1);
    for(i=0;i<=length;i++)
    result[i]=0;
    
    for(h=j;h>0;h--)
    {
                    low=power(2,h-1);
                    high=power(2,h);
                    if(h==j)
                    for(i=low;i<high;i++)
                    {
                                         result[k]=i+1;
                                         result[k+1]=i;
                                         result[k+2]=i/2;
                                         k=k+j;
                                         i++;
                    }
                    else
                    for(m=0;m<=length;m++)
                    {
                                          if(result[m]==0)
                                          {
                                                          if(result[m-1]%2!=0)
                                                          result[m]=result[m-1]/2;
                                                          while(result[m]==0)
                                                          m++;
                                          }
                    }
    }
    j=0;
    for(i=0;i<=length;i++)
    {
                          if(result[i]!=0)
                          {
                                          result[j]=result[i];
                                          j++;
                          }
    }
}

//--------------------------END-----------------------

//function to traverse the tree according inorder,preorder,postorder

void traverse_result()
{
     
     int i;
     for(i=0;i<height;i++)
     traverse[i]=-1;
     
     for(i=0;i<height;i++)
     traverse[i]=tree_nodes[result[i]];
     
     for(i=0;i<height;i++)
     if(traverse[i]!=-1)
     printf("%d ",traverse[i]);
     
     
}

//----------------------END-----------------------

//function to calculate power of a to b

int power(int a,int b)
{
    int i,p=1;
    for(i=0;i<b;i++)
    p=p*a;
    
    return p;
}

//-----------------------END--------------------
