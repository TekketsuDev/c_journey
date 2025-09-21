#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *buf;
  size_t len;
  size_t cap;
} sbuf;

void sbuf_init(sbuf *s);
void sbuf_free(sbuf *s);
bool sbuf_reserve(sbuf *s, size_t extra);
bool sbuf_putc(sbuf *s, char c);
bool sbuf_write(sbuf *s, const char *txt);

bool json_escape(sbuf *s, const char *str);

typedef struct {
  bool first;
} json_obj;

bool json_begin_obj(sbuf *s, json_obj *o);
bool json_end_obj(sbuf *s);
bool json_comma_if_needed(sbuf *s, json_obj *o);
bool json_key(sbuf *s, json_obj *o, const char *key);
bool json_key_str_if(sbuf *s, json_obj *o, const char *key, const char *val);
