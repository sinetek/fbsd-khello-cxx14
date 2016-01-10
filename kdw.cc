extern "C"
{
/* tentative include files */
#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>
}

void hello(struct module &mod)
{
	uprintf("Hello!\n");
}

void bye(struct module &mod)
{
	uprintf("Bye!\n");
}

/* The function called at load/unload */
static int event_handler(struct module *mod, int event, void *arg) {
	int e = 0;

	switch (event) {
	case MOD_LOAD:
		hello(*mod);
		break;
	case MOD_UNLOAD:
		bye(*mod);
		break;
	default:
		e = EOPNOTSUPP;
		break;
	}

	return (e);
}

/* The second argument of DECLARE_MODULE */
static moduledata_t kdw_conf = {
	"kdw",	/* module name */
	event_handler,
	NULL	/* extra data */
};

//
DECLARE_MODULE(kdw, kdw_conf, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);

