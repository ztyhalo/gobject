#include "pm-dlist.h"
#include <stdlib.h>


G_DEFINE_TYPE(PMDlist, pm_dlist, G_TYPE_OBJECT);


static void pm_dlist_init(PMDlist *self)
{
	g_printf("\t 实例结构体初始化！\n");
	self->head = NULL;
	self->tail = NULL;
}


static void pm_dlist_class_init(PMDlistClass * klass)
{
	g_printf("类结构体初始化！\n");
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
