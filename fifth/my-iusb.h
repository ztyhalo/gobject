#ifndef __MY_IUSB_H__
#define __MY_IUSB_H__

#include <glib-object.h>


#define MY_TYPE_IUSB(my_iusb_get_type())

#define MY_IUSB(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MY_TYPE_IUSB, MyIUsb))

typedef struct _MyIUsb MyIUsb;

typedef struct _MyIUsbInterface MyIUsbInterface;


