#include "pm-dlist.h"
#include <stdlib.h>


G_DEFINE_TYPE(PMDlist, pm_dlist, G_TYPE_OBJECT);

typedef struct _PMDlistPrivate PMDlistPrivate;
struct _PMDlistPrivate{
	PMDlistPrivate *head;
	PMDlistPrivate *tail;
};	

#define PM_DLIST_GET_PAIVATE(obj) (\
	G_TYPE_INSTANCE_GET_PRIVATE((obj), PM_TYPE_DLIST,PMDlistPrivate ))

static void pm_dlist_init(PMDlist *self)
{
	g_printf("\t 实例结构体初始化！\n");
	PMDlistPrivate * priv = PM_DLIST_GET_PAIVATE(self);
	priv->head = NULL;
	priv->tail = NULL;
}


static void pm_dlist_class_init(PMDlistClass * klass)
{
	g_printf("类结构体初始化！\n");
	g_type_class_add_private(klass, sizeof(PMDlistPrivate));
}



int main(void)
{
	g_type_init();
	int i; 
	PMDlist *list;
	for(i = 0; i < 3; i++){
		list = g_object_new(PM_TYPE_DLIST, NULL);
		g_object_unref(list);
	}
	
	list = g_object_new(PM_TYPE_DLIST , NULL);
	if(G_IS_OBJECT(list))
		g_printf("\t这是一个GObject 对象!\n");
	return 0;
}
