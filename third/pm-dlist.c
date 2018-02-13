/*change */
#include "pm-dlist.h"
#include <stdlib.h>


G_DEFINE_TYPE(PMDlist, pm_dlist, G_TYPE_OBJECT);

typedef struct _PMDlistPrivate PMDlistPrivate;
struct _PMDlistPrivate{
	PMDlistNode *head;
	PMDlistNode *tail;
};	


#define PM_DLIST(object) (\
        G_TYPE_CHECK_INSTANCE_CAST((object), PM_TYPE_DLIST, PMDlist))

#define PM_DLIST_GET_PRIVATE(obj) (\
	G_TYPE_INSTANCE_GET_PRIVATE((obj), PM_TYPE_DLIST,PMDlistPrivate ))
PMDlistNode * pm_dlist_get(PMDlist *self, PM_DLIST_PROPERTY property)
{
	PMDlistNode * node = NULL;
	PMDlistPrivate * priv = PM_DLIST_GET_PRIVATE(self); 
	switch (property){
	case PM_DLIST_HEAD:
		node = priv->head;
		break;
	case PM_DLIST_TAIL:
		node = priv->tail;
		break;
	default:
		g_printf("对不起，你访问的成员不存在!\n");
	}
	return node;
}

void pm_dlist_set(PMDlist *self, PM_DLIST_PROPERTY property,
		  PM_DLIST_PROPERTY subproperty, PMDlistNode * node)
{
	PMDlistPrivate * priv = PM_DLIST_GET_PRIVATE(self);
	switch (property) {
	case PM_DLIST_HEAD:
		if(subproperty == PM_DLIST_NODE_PREV)
		 	priv->head->prev =node;
		else if(subproperty == PM_DLIST_NODE_NEXT)
			priv->head->next = node;
		break;
	case PM_DLIST_TAIL:
		if(subproperty == PM_DLIST_NODE_PREV)
		 	priv->tail->prev =node;
		else if(subproperty == PM_DLIST_NODE_NEXT)
			priv->tail->next = node;
		break;
	default:
		g_printf("对不起，你访问的成员不存在!\n");
	}
}



static void pm_dlist_set_property(GObject *object, guint property_id, 
				  const GValue *value, GParamSpec *pspec)
{
	PMDlist *self = PM_DLIST(object);
	PMDlistPrivate * pri = PM_DLIST_GET_PRIVATE(self);
	switch (property_id) {
	case PROPERTY_DLIST_HEAD:
		pri->head = g_value_get_pointer(value);
		break;
	case PROPERTY_DLIST_HEAD_PREV:
		pri->head->prev = g_value_get_pointer(value);
		break;
	case PROPERTY_DLIST_HEAD_NEXT:
		pri->head->next = g_value_get_pointer(value);
		break;
	case PROPERTY_DLIST_TAIL:
		pri->tail = g_value_get_pointer(value);
		break;
	case PROPERTY_DLIST_TAIL_PREV:
		pri->tail->prev = g_value_get_pointer(value);
		break;
	case PROPERTY_DLIST_TAIL_NEXT:
		pri->tail->next = g_value_get_pointer(value);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id , pspec);
	break;
	}
	
}
static void
pm_dlist_get_property(GObject *object, guint property_id,
		 	GValue *value, GParamSpec * pspec)
{
	PMDlist *self = PM_DLIST(object);
	PMDlistPrivate *priv = PM_DLIST_GET_PRIVATE(self);
	
	switch(property_id){
	case PROPERTY_DLIST_HEAD:
		g_value_set_pointer(value, priv->head);
		break;
	case PROPERTY_DLIST_HEAD_PREV:
		g_value_set_pointer(value, priv->head->prev);
		break;
	case PROPERTY_DLIST_HEAD_NEXT:
		g_value_set_pointer(value, priv->head->next);
		break;
	case PROPERTY_DLIST_TAIL:
		g_value_set_pointer(value, priv->tail);
		break;
	case PROPERTY_DLIST_TAIL_PREV:
		g_value_set_pointer(value, priv->tail->prev);
		break;
	case PROPERTY_DLIST_TAIL_NEXT:
		g_value_set_pointer(value, priv->tail->next);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id,pspec);
		break;
	}
}
static void pm_dlist_init(PMDlist *self)
{
	g_printf("\t 实例结构体初始化！\n");
	PMDlistPrivate * priv = PM_DLIST_GET_PRIVATE(self);
	priv->head = NULL;
	priv->tail = NULL;
	g_printf("\t 实例结构体初始化结束！\n");
}


static void pm_dlist_class_init(PMDlistClass * klass)
{
	g_printf("类结构体初始化！\n");
	g_type_class_add_private(klass, sizeof(PMDlistPrivate));
	GObjectClass * base_class = G_OBJECT_CLASS(klass);
	base_class->set_property = pm_dlist_set_property;
	base_class->get_property = pm_dlist_get_property;

	GParamSpec *pspec;

	pspec = g_param_spec_pointer("head",
				    "Head node",
				   "The head node of the double list",
		                   G_PARAM_READABLE | G_PARAM_WRITABLE| G_PARAM_CONSTRUCT);
	g_object_class_install_property(base_class, PROPERTY_DLIST_HEAD, pspec);
	
	pspec = g_param_spec_pointer("head-prev",
					"the previous node of the head node",
					"the previous node of the head node",
					G_PARAM_READABLE|G_PARAM_WRITABLE);	
	g_object_class_install_property(base_class, PROPERTY_DLIST_HEAD_PREV, pspec);
	
	pspec = g_param_spec_pointer("head-next",
					"the next node of the head node",
					"the next node of the head node",
					G_PARAM_READABLE|G_PARAM_WRITABLE);
	g_object_class_install_property(base_class, PROPERTY_DLIST_HEAD_NEXT, pspec);

	
	pspec = g_param_spec_pointer("tail",
					"Tail node",
					"The tail node of the double list",
					G_PARAM_READABLE | G_PARAM_WRITABLE| G_PARAM_CONSTRUCT);
	g_object_class_install_property(base_class, PROPERTY_DLIST_TAIL, pspec);



	pspec = g_param_spec_pointer("tail-prev",
					"The previous node of the tail node",
					"The previous node of the tail node",
					G_PARAM_READABLE | G_PARAM_WRITABLE  );
	g_object_class_install_property(base_class, PROPERTY_DLIST_TAIL_PREV, pspec);

	pspec = g_param_spec_pointer("tail-next",
					"The next node of the tail node",
					"The next node of the tail node",
					G_PARAM_READABLE | G_PARAM_WRITABLE  );
	g_object_class_install_property(base_class, PROPERTY_DLIST_TAIL_NEXT , pspec);

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

