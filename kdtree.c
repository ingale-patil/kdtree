#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "kdtree.h"

void init(kdtree *kd){
	*kd=NULL;

}



float distance(int x1,int x2,int y1,int y2){
    float distance=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return distance;
}



void inorder(kdtree t) {
	if(t==NULL){
	    return;
	}
	inorder(t->left);
	printf(" ( %f , %f ) ", t->x,t->y);	
	inorder(t->right);
	return;
}

void insert(kdtree *kd,float a,float b,int level){
	kd_node *nn,*p,*q;
	//int level=0;
	p=*kd;
	nn=malloc(sizeof(kd_node));
	nn->x=a;
	nn->y=b;
	//nn->city=s;
	nn->left=nn->right=nn->parent=NULL;
	
	if(*kd == NULL){
		*kd=nn;
		//printf("%d %d",nn->x,nn->y);
		//printf("insert done\n");
		//return;
		
	}
	else{
	if(level%2==0){
	    //compare with x 
	    if(a == p->x){
	        if(b > p->y){
	            level++;
	            insert(&p->right,a,b,level);
	            p->right->parent=p;
	        }
	        else{
	            level++;
	            insert(&p->left,a,b,level);
	            p->left->parent=p;
	        }
	    }
	    
	    else if(a > p->x){
	        //p=p->right;
	        level++;
	        insert(&p->right,a,b,level); //recursively
	        p->right->parent=p;
	        
	    }
	    else {
	        level++;
	        insert(&p->left,a,b,level);
	        p->left->parent=p;
	    }
	}
	else{
	    //compare with y
	    if(b == p->y){
	        if(b > p->x){
	            level++;
	            insert(&p->right,a,b,level);
	            p->right->parent=p;
	        }
	        else{
	            level++;
	            insert(&p->left,a,b,level);
	            p->left->parent=p;
	        }
	    }
	    else if(b >= p->y){
	        level++;
	        insert(&p->right,a,b,level);
	        p->right->parent=p;
	    }
	    else{
	        level++;
	        insert(&p->left,a,b,level);
	        p->left->parent=p;
	    }
	}
	}
}


void preorder(kdtree t) {
	if(t == NULL)
		return;
	printf(" ( %f, %f) ", t->x,t->y);	
	preorder(t->left);
	preorder(t->right);
}





void nearest_neighbour(kdtree kd,float a,float b){
    //kd_node *p=search(kd,u,v,0);
    //printf(" %d %d ",p->parent->x,p->parent->y);
    //nearest* nn;
    float min_distance=10000;
    float x=10000;
    float y=10000;
    kd_node *p;
	int level=0;
	static float arr[2]={0};
	static float dist=0;
	p=kd;
	//float min_distance=INT_MAX;
    //float x=INT_MAX;
    //float y=INT_MAX;
	
	
	
    while(p!=NULL){
	if(level%2==0){
	    //compare with x 
	    if(a == p->x){
	        if(b > p->y){
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
				
				
				p=p->right;
	            
	        }
	        else{
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
				
				p=p->left;
	            
	        }
	    }
	    
	    else if(a > p->x){
	        //p=p->right;
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			
		    if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
			p=p->right;
	        //search(p->right,a,b,level); //recursively
	        //p->right->parent=p;
	        
	    }
	    else {
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
			p=p->left;
	        //search(p->left,a,b,level);
	        //p->left->parent=p;
	    }
	}
	else{
	    //compare with y
	    if(b == p->y){
	        if(b > p->x){
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
				p=p->right;
	            //search(p->right,a,b,level);
	            //p->right->parent=p;
	        }
	        else{
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
				p=p->left;
	            //search(p->left,a,b,level);
	            //p->left->parent=p;
	        }
	    }
	    else if(b >= p->y){
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
			p=p->right;
	        //search(p->right,a,b,level);
	        //p->right->parent=p;
	    }
	    else{
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist < min_distance){
				    min_distance = dist;
				    x = p->x;
				    y = p->y;
				}
			p=p->left;
	        //search(p->left,a,b,level);
	        //p->left->parent=p;
	    }
	}
	
    }
    printf("\n===========================================================================");
    printf("\n Most Nearest is ( %f , %f ) And Distance is %f",x,y,min_distance);
    printf("\n===========================================================================");
    //return nn;
    
    
}


void search(kdtree kd,float a,float b,float r){
	kd_node *p;
	int level=0;
	static float arr[2]={0};
	static float dist=0;
	p=kd;
	float min_distance=INT_MAX;
    float x=INT_MAX;
    float y=INT_MAX;
	
	
	
    while(p!=NULL){
	if(level%2==0){
	    //compare with x 
	    if(a == p->x){
	        if(b > p->y){
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				min_distance=dist;
				x=p->x;
				y=p->y;
				if(dist<r){
				printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
				printf("-- %.3f ",dist);
				    
				}
				
				p=p->right;
	            //search(p->right,a,b,level);
	            //p->right->parent=p;
	        }
	        else{
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				
				
				if(dist<r){
				printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
				printf(" %.3f ",dist);
				}
				
				p=p->left;
	            //search(p->left,a,b,level);
	            //p->left->parent=p;
	        }
	    }
	    
	    else if(a > p->x){
	        //p=p->right;
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			
			if(dist<r){
			printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
			printf(" %.3f ",dist);
			}
			p=p->right;
	        //search(p->right,a,b,level); //recursively
	        //p->right->parent=p;
	        
	    }
	    else {
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist<r){
			printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
			printf(" %0.3f ",dist);
			}
			p=p->left;
	        //search(p->left,a,b,level);
	        //p->left->parent=p;
	    }
	}
	else{
	    //compare with y
	    if(b == p->y){
	        if(b > p->x){
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist<r){
				printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
				printf(" %.3f ",dist);
				    
				}
				p=p->right;
	            //search(p->right,a,b,level);
	            //p->right->parent=p;
	        }
	        else{
	            level++;
	            arr[0]=p->x;
				arr[1]=p->y;
				dist=distance(a,p->x,b,p->y);
				if(dist<r){
				printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
				printf(" %.3f ",dist);
		
				}
				p=p->left;
	            //search(p->left,a,b,level);
	            //p->left->parent=p;
	        }
	    }
	    else if(b >= p->y){
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist<r){
			printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
			printf(" %.3f ",dist);
			}
			p=p->right;
	        //search(p->right,a,b,level);
	        //p->right->parent=p;
	    }
	    else{
	        level++;
	        arr[0]=p->x;
			arr[1]=p->y;
			dist=distance(a,p->x,b,p->y);
			if(dist<r){
			printf("\n ->Nearest Neighbour [%f , %f] --",arr[0],arr[1]);
			printf(" %.3f ",dist);
			    
			}
			p=p->left;
	        //search(p->left,a,b,level);
	        //p->left->parent=p;
	    }
	}
	}
	

}





/*void most_nearest(kdtree kd,float x,float y){
    nearest * p=nearest_neighbour(kd,x,y);
    printf("==================================================================\n");
    printf("Most Nearest is ( %f , %f ) And Distance is %f",p->x,p->y,p->distance);
}*/