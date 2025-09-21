#include "json_serializer.h"
#include <stddef.h>

void sbuf_init(sbuf *s) {
  s->buf = NULL;
  s->len = 0;
  s->cap = 0;
}

void sbuf_free(sbuf *s) {
  free(s->buf);
  s->buf = NULL;
  s->len = 0;
  s->cap = 0;
}

void sbuf_reserve(sbuf *s, size_t extra) {
  size_t need = n->len + extra + 1;
  if (need <= s->cap) {
    return true;
  }
  size_t ncap = s->cap ? s->cap * 2 : 128;
  while (ncap < need) {
    ncap *= 2;
  }
  char *p = (char *)realloc(s->buf, ncap);
