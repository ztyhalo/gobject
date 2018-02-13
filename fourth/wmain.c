#include "kb-bibtex.h"

int main(void)
{
	g_type_init();
	
	KbBibtex * entry = g_object_new(KB_TYPE_BIBTEX,
					"title", "The {\\TeX}Book",
					"author", "Knuth, D. E.",
					"publisher", "Addison-Wesley",
					"year", 1984,
					NULL);
	gchar * title, *author, * publisher;
	guint year;
	
	g_object_get (G_OBJECT(entry),
			"title", &title,
			"author", &author,
			"publisher", &publisher,
			"year",   &year,
			NULL);
	g_printf("  Title: %s\n"
		 " Author:%s\n"
		"publisher: %s\n"
		"   year: %d\n", title, author, publisher, year);
	g_free(title);
	g_free(author);
	g_free(publisher);
	
	g_object_unref(entry);
	return 0;
}
