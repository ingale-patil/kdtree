typedef struct kd_node{
	float x;
	float y;
	//char *city;
	struct kd_node *left,*right,*parent;
}kd_node;

typedef struct nearest{
    float x;
    float y;
    float distance;
}nearest;

typedef kd_node *kdtree;

void init(kdtree *kd);
//void insert(kdtree *kd,int x,int y);
void inorder(kdtree t);
void insert(kdtree *kd,float a,float b,int level);
void preorder(kdtree t);
void insert_node(kdtree *kd,int x,int y);
//kd_node* search(kdtree kd,int a,int b,int level);
void search(kdtree kd,float a,float b,float r);
//void nearest_neighbour(kdtree kd,float u,float v);
void nearest_neighbour(kdtree kd,float u,float v);
//void most_nearest(kdtree kd,float x,float y);