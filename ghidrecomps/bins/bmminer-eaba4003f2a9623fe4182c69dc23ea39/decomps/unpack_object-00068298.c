
int unpack_object(scanner_t *s,json_t *root,va_list *ap)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  json_t *pjVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  undefined4 uVar8;
  char **ppcVar9;
  bool bVar10;
  va_list *ap_local;
  json_t *root_local;
  scanner_t *s_local;
  strbuffer_t unrecognized_keys;
  hashtable_t key_set;
  json_t *value_1;
  char *key;
  long unpacked;
  int have_unrecognized_keys;
  char *key_1;
  int opt;
  json_t *value;
  int gotopt;
  int strict;
  int ret;
  
  ret = -1;
  strict = 0;
  bVar1 = false;
  iVar2 = hashtable_init(&key_set);
  if (iVar2 != 0) {
    set_error(s,"<internal>","Out of memory");
    return -1;
  }
  if ((root == (json_t *)0x0) || ((root != (json_t *)0x0 && (root->type == JSON_OBJECT)))) {
    next_token(s);
    while ((s->token).token != '}') {
      if (strict != 0) {
        if (strict == 1) {
          uVar8 = 0x21;
        }
        else {
          uVar8 = 0x2a;
        }
        set_error(s,"<format>","Expected \'}\' after \'%c\', got \'%c\'",uVar8,
                  (uint)(byte)(s->token).token);
        goto out;
      }
      if ((s->token).token == '\0') {
        set_error(s,"<format>","Unexpected end of format string");
        goto out;
      }
      if (((s->token).token == '!') || ((s->token).token == '*')) {
        if ((s->token).token == '!') {
          strict = 1;
        }
        else {
          strict = -1;
        }
        next_token(s);
      }
      else {
        if ((s->token).token != 's') {
          set_error(s,"<format>","Expected format \'s\', got \'%c\'",(uint)(byte)(s->token).token);
          goto out;
        }
        ppcVar9 = (char **)ap->__ap;
        ap->__ap = ppcVar9 + 1;
        pcVar7 = *ppcVar9;
        if (pcVar7 == (char *)0x0) {
          set_error(s,"<args>","NULL object key");
          goto out;
        }
        next_token(s);
        bVar10 = (s->token).token == '?';
        if (bVar10) {
          bVar1 = true;
          next_token(s);
        }
        if (root == (json_t *)0x0) {
          value = (json_t *)0x0;
        }
        else {
          value = json_object_get(root,pcVar7);
          if ((value == (json_t *)0x0) && (!bVar10)) {
            set_error(s,"<validation>","Object item not found: %s",pcVar7);
            goto out;
          }
        }
        iVar2 = unpack(s,value,ap);
        if (iVar2 != 0) goto out;
        pjVar4 = json_null();
        hashtable_set(&key_set,pcVar7,pjVar4);
        next_token(s);
      }
    }
    if ((strict == 0) && ((s->flags & 2) != 0)) {
      strict = 1;
    }
    if ((root != (json_t *)0x0) && (strict == 1)) {
      bVar10 = false;
      unpacked = 0;
      if (bVar1) {
        pvVar3 = json_object_iter(root);
        key_1 = json_object_iter_key(pvVar3);
        while (key_1 != (char *)0x0) {
          pvVar3 = json_object_key_to_iter(key_1);
          pjVar4 = json_object_iter_value(pvVar3);
          if (pjVar4 == (json_t *)0x0) break;
          pvVar3 = hashtable_get(&key_set,key_1);
          if (pvVar3 == (void *)0x0) {
            unpacked = unpacked + 1;
            if (bVar10) {
              strbuffer_append_bytes(&unrecognized_keys,", ",2);
            }
            else {
              strbuffer_init(&unrecognized_keys);
              bVar10 = true;
            }
            sVar6 = strlen(key_1);
            strbuffer_append_bytes(&unrecognized_keys,key_1,sVar6);
          }
          pvVar3 = json_object_key_to_iter(key_1);
          pvVar3 = json_object_iter_next(root,pvVar3);
          key_1 = json_object_iter_key(pvVar3);
        }
      }
      else {
        sVar5 = json_object_size(root);
        unpacked = sVar5 - key_set.size;
      }
      if (unpacked != 0) {
        if (!bVar1) {
          pvVar3 = json_object_iter(root);
          key_1 = json_object_iter_key(pvVar3);
          while (key_1 != (char *)0x0) {
            pvVar3 = json_object_key_to_iter(key_1);
            pjVar4 = json_object_iter_value(pvVar3);
            if (pjVar4 == (json_t *)0x0) break;
            pvVar3 = hashtable_get(&key_set,key_1);
            if (pvVar3 == (void *)0x0) {
              if (bVar10) {
                strbuffer_append_bytes(&unrecognized_keys,", ",2);
              }
              else {
                strbuffer_init(&unrecognized_keys);
                bVar10 = true;
              }
              sVar6 = strlen(key_1);
              strbuffer_append_bytes(&unrecognized_keys,key_1,sVar6);
            }
            pvVar3 = json_object_key_to_iter(key_1);
            pvVar3 = json_object_iter_next(root,pvVar3);
            key_1 = json_object_iter_key(pvVar3);
          }
        }
        pcVar7 = strbuffer_value(&unrecognized_keys);
        set_error(s,"<validation>","%li object item(s) left unpacked: %s",unpacked,pcVar7);
        strbuffer_close(&unrecognized_keys);
        goto out;
      }
    }
    ret = 0;
  }
  else {
    set_error(s,"<validation>","Expected object, got %s",type_names[root->type]);
  }
out:
  hashtable_close(&key_set);
  return ret;
}

