/*change */
/* gobject study */

#ifndef __PM_DLIST_H__
#define __PM_DLIST_H__

#include <glib-object.h>

#define PM_TYPE_DLIST (pm_dlist_get_type ())

typedef struct _PMDlistNode PMDlistNode;

typedef enum _PM_DLIST_PROPERTY  PM_DLIST_PROPERTY;

enum  _PM_DLIST_PROPERTY {
	PM_DLIST_HEAD,
	PM_DLIST_TAIL,
	PM_DLIST_NODE_PREV,
	PM_DLIST_NODE_NEXT
}; 

enum PropertyDlist{
	PROPERTY_DLIST_0,
	PROPERTY_DLIST_HEAD,
	PROPERTY_DLIST_HEAD_PREV,
	PROPERTY_DLIST_HEAD_NEXT,
	PROPERTY_DLIST_TAIL,
	PROPERTY_DLIST_TAIL_PREV,
	PROPERTY_DLIST_TAIL_NEXT
};

struct _PMDlistNode {
	PMDlistNode    *prev; 
	PMDlistNode	*next;
	void *		data; 
};

typedef struct _PMDlist PMDlist;
typedef struct _PMDlist {
	GObject parent_instance;
};

typedef struct _PMDlistClass PMDlistClass;
struct _PMDlistClass {
	GObjectClass parent_class;
};

GType pm_dlist_get_type (void);

#endif
