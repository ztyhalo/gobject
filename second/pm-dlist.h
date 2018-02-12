/* gobject study */

#ifndef __PM_DLIST_H__
#define __PM_DLIST_H__

#include <glib-object.h>

#define PM_TYPE_DLIST (pm_dlist_get_type ())

typedef struct _PMDlistNode PMDlistNode;

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
