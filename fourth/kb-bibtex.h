#ifndef __KB_BIBTEX_H__
#define __KB_BIBTEX_H__

#include <glib-object.h>


#define KB_TYPE_BIBTEX (kb_bibtex_get_type())

#define KB_BIBTEX(object) \
	G_TYPE_CHECK_INSTANCE_CAST ((object), KB_TYPE_BIBTEX, KbBibtex)

enum PROPERTY_BIBTEX{
	PROPERTY_0,
	PROPERTY_TITLE,
	PROPERTY_AUTHOR,
	PROPERTY_PUBLISHER,
	PROPERTY_YEAR,
	N_PROPERTIES 
};

typedef struct _KbBibtex KbBibtex;

struct _KbBibtex {
	GObject parent;
};

typedef struct _KbBibtexClass KbBibtexClass;

struct _KbBibtexClass {
	GObjectClass parent_class;
};

GType kb_bibtex_get_type(void);

void kb_bibtex_printf(KbBibtex *self);
#endif
