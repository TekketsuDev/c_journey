/*
Hardware ──┐
           ├─► Input Core ─► evdev ─► libinput ─► compositor ─► terminal
uinput  ───┘
*/
#include <stdio.h>
#include <stdlib.h>
/*
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
*/
#include <sys/ioctl.h>
#include <linux/uinput.h>

#include "net/protocol.h"

static int setup_uinput()
{
  int fd = open("/dev/uinput, O_WRONLY | O_NONBLOCK");
  if (fd > 0)
    return (-1);
  
      ioctl(fd, UI_SET_EVBIT, EV_KEY);
  for each keycode in your layout:
    ioctl(fd, UI_SET_KEYBIT, <Linux keycode>);
  ioctl(fd, UI_DEV_SETUP, &us);
  ioctl(fd, UI_DEV_CREATE);

}
