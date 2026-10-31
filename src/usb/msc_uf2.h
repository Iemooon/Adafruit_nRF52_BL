#ifndef MSC_UF2_H
#define MSC_UF2_H

// Called from the USB task loop; never waits or resets inside a data callback.
void msc_uf2_task(void);

#endif
