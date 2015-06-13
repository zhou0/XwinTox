#ifndef XWINTOX_H_
#define XWINTOX_H_

#include "dictionary.h"
#include "list.h"

typedef struct Xwin_s
{
	thrd_t Thrd;
	List_t* ICQueue;
} Xwin_t;

typedef struct Comm_s
{
	int WantQuit;
	int Work;
	cnd_t WorkCnd;
	mtx_t WorkMtx;
	List_t *WorkQueue;
} Comm_t;

typedef struct XwinTox_instance_s
{
	Xwin_t *Xwin;
	Comm_t *Comm;

	int Connected;

	Dictionary_t *Config;
	char* ConfigFilename;
} XwinTox_instance_t;



#ifdef __cplusplus__
extern "C" {
#endif
extern XwinTox_instance_t *APP;
void CommWork();
#ifdef __cplusplus__
}
#endif

#endif
