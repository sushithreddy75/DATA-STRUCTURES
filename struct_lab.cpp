#include<iostream>
using namespace std;
struct s10
{
    int y;
    s10 *z;
};
struct s9
{
    s9 *w;
    int x;
};
struct s8
{
    s9 *t;
    int u;
    s10 *v;
};
struct s7
{
    int n;
    char o;
    s8 *p;
};
struct s6
{
    s7 *q;
    int r;
    s6 *s;
};
struct s5
{
    int l;
    s6 *m;
};
struct s4
{
    s7 *j;
    s5 *k;
};
struct s3
{
    s4 *g;
    s3 *h;
    s5 *i;
};
struct s2
{
    char e;
    s3 *f;
};
struct s1
{
    s1 *a;
    int b;
    s2 *c;
    s1 *d;
};
int main()
{
    s1 str;
    str.c=new(s2);
    str.c->f=new(s3);
    str.c->f->i=new(s5);
    str.c->f->i->m=new(s6);
    str.c->f->g=new(s4);
    str.c->f->g->j=new(s7);
    str.c->f->g->j->p=new(s8);
    str.c->f->g->j->p->t=new(s9);
    str.c->f->g->j->p->v=new(s10);
    cin>>str.c->f->g->j->n;
    cin>>str.c->f->i->m->r;
    cin>>str.c->f->g->j->p->u;
    int flag=0;
    if(str.c->f->g->j->p->u%2==1)
    flag=1;
    if(flag==0)
    {
        str.c->f->g->j->p->t->x=str.c->f->g->j->n;
        str.c->f->g->j->p->v->y=str.c->f->i->m->r;
    }
    else
    {
        str.c->f->g->j->p->t->x=str.c->f->i->m->r;
        str.c->f->g->j->p->v->y=str.c->f->g->j->n;
    }
    cout<<str.c->f->g->j->n<<" "<<str.c->f->i->m->r<<" "<<str.c->f->g->j->p->u<<" "<<str.c->f->g->j->p->t->x<<" "<<str.c->f->g->j->p->v->y<<endl;
    return 0;
}
