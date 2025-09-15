
/* WARNING: Unknown calling convention */

int unpack(scanner_t *s,json_t *root,va_list *ap)

{
  int iVar1;
  json_t *pjVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  uint uVar6;
  json_type jVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  json_int_t *pjVar10;
  double *pdVar11;
  char *pcVar12;
  bool bVar13;
  double dVar14;
  json_int_t jVar15;
  hashtable_t key_set;
  
  switch((s->token).token) {
  case 'F':
    if ((root != (json_t *)0x0) && (1 < root->type - JSON_INTEGER)) {
      set_error(s,"<validation>","Expected real or integer, got %s",type_names[root->type]);
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      pdVar11 = (double *)*puVar8;
      if (root != (json_t *)0x0) {
        dVar14 = json_number_value(root);
        *pdVar11 = dVar14;
        return 0;
      }
    }
    break;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'");
    return -1;
  case 'I':
    if ((root != (json_t *)0x0) && (jVar7 = root->type, jVar7 != JSON_INTEGER)) {
LAB_0003bd90:
      set_error(s,"<validation>","Expected integer, got %s",type_names[jVar7]);
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      pjVar10 = (json_int_t *)*puVar8;
      if (root != (json_t *)0x0) {
        jVar15 = json_integer_value(root);
        *pjVar10 = jVar15;
        return 0;
      }
    }
    break;
  case 'O':
    uVar6 = s->flags;
    if (root == (json_t *)0x0) goto LAB_0003bba8;
    if ((int)(uVar6 << 0x1f) < 0) {
      return 0;
    }
    if (root->refcount == 0xffffffff) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      puVar8 = (undefined4 *)*puVar8;
    }
    else {
      puVar8 = (undefined4 *)ap->__ap;
      root->refcount = root->refcount + 1;
      ap->__ap = puVar8 + 1;
      puVar8 = (undefined4 *)*puVar8;
    }
    goto LAB_0003bbb8;
  case '[':
    if ((root != (json_t *)0x0) && (root->type != JSON_ARRAY)) {
      set_error(s,"<validation>","Expected array, got %s",type_names[root->type]);
      return -1;
    }
    iVar1 = 0;
    sVar5 = 0;
    next_token(s);
    while (uVar6 = (uint)(byte)(s->token).token, uVar6 != 0x5d) {
      while( true ) {
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            uVar9 = 0x21;
          }
          else {
            uVar9 = 0x2a;
          }
          set_error(s,"<format>","Expected \']\' after \'%c\', got \'%c\'",uVar9,uVar6);
          return -1;
        }
        if (uVar6 == 0) {
          set_error(s,"<format>","Unexpected end of format string");
          return -1;
        }
        if (uVar6 != 0x21 && uVar6 != 0x2a) break;
        if (uVar6 == 0x21) {
          iVar1 = 1;
        }
        else {
          iVar1 = -1;
        }
        next_token(s);
        uVar6 = (uint)(byte)(s->token).token;
        if (uVar6 == 0x5d) goto LAB_0003bad4;
      }
      pcVar12 = strchr("{[siIbfFOon",uVar6);
      if (pcVar12 == (char *)0x0) {
        set_error(s,"<format>","Unexpected format character \'%c\'",uVar6);
        return -1;
      }
      if (root == (json_t *)0x0) {
        pjVar2 = (json_t *)0x0;
      }
      else {
        pjVar2 = json_array_get(root,sVar5);
        if (pjVar2 == (json_t *)0x0) {
          set_error(s,"<validation>","Array index %lu out of range",sVar5);
          return -1;
        }
      }
      iVar3 = unpack(s,pjVar2,ap);
      if (iVar3 != 0) {
        return -1;
      }
      sVar5 = sVar5 + 1;
      next_token(s);
    }
LAB_0003bad4:
    if (iVar1 == 0) {
      if (-1 < (int)(s->flags << 0x1e)) {
        return 0;
      }
      bVar13 = true;
    }
    else {
      bVar13 = iVar1 == 1;
    }
    if (root == (json_t *)0x0) {
      bVar13 = false;
    }
    if ((bVar13) && (sVar4 = json_array_size(root), sVar5 != sVar4)) {
      sVar4 = json_array_size(root);
      set_error(s,"<validation>","%li array item(s) left unpacked",sVar4 - sVar5);
      return -1;
    }
    break;
  case 'b':
    if ((root != (json_t *)0x0) && (1 < root->type - JSON_TRUE)) {
      set_error(s,"<validation>","Expected true or false, got %s",type_names[root->type]);
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      if (root != (json_t *)0x0) {
        *(uint *)*puVar8 = (uint)(root->type == JSON_TRUE);
        return 0;
      }
    }
    break;
  case 'f':
    if ((root != (json_t *)0x0) && (root->type != JSON_REAL)) {
      set_error(s,"<validation>","Expected real, got %s",type_names[root->type]);
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      pdVar11 = (double *)*puVar8;
      if (root != (json_t *)0x0) {
        dVar14 = json_real_value(root);
        *pdVar11 = dVar14;
        return 0;
      }
    }
    break;
  case 'i':
    if ((root != (json_t *)0x0) && (jVar7 = root->type, jVar7 != JSON_INTEGER)) goto LAB_0003bd90;
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      puVar8 = (undefined4 *)*puVar8;
      if (root != (json_t *)0x0) {
        jVar15 = json_integer_value(root);
        *puVar8 = (int)jVar15;
        return 0;
      }
    }
    break;
  case 'n':
    if ((root != (json_t *)0x0) && (root->type != JSON_NULL)) {
      set_error(s,"<validation>","Expected null, got %s",type_names[root->type]);
      return -1;
    }
    break;
  case 'o':
    uVar6 = s->flags;
LAB_0003bba8:
    if ((uVar6 & 1) != 0) {
      return 0;
    }
    puVar8 = (undefined4 *)ap->__ap;
    ap->__ap = puVar8 + 1;
    puVar8 = (undefined4 *)*puVar8;
    if (root == (json_t *)0x0) {
      return 0;
    }
LAB_0003bbb8:
    *puVar8 = root;
    break;
  case 's':
    if ((root != (json_t *)0x0) && (root->type != JSON_STRING)) {
      set_error(s,"<validation>","Expected string, got %s",type_names[root->type]);
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      puVar8 = (undefined4 *)*puVar8;
      if (puVar8 == (undefined4 *)0x0) {
        set_error(s,"<args>","NULL string argument");
        return -1;
      }
      if (root != (json_t *)0x0) {
        pcVar12 = json_string_value(root);
        *puVar8 = pcVar12;
        return 0;
      }
    }
    break;
  case '{':
    iVar1 = hashtable_init(&key_set);
    if (iVar1 != 0) {
      set_error(s,"<internal>","Out of memory");
      return -1;
    }
    if ((root != (json_t *)0x0) && (root->type != JSON_OBJECT)) {
      iVar1 = -1;
      set_error(s,"<validation>","Expected object, got %s",type_names[root->type]);
      goto LAB_0003b9de;
    }
    iVar1 = 0;
    next_token(s);
    while (uVar6 = (uint)(byte)(s->token).token, uVar6 != 0x7d) {
      while( true ) {
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            uVar9 = 0x21;
          }
          else {
            uVar9 = 0x2a;
          }
          iVar1 = -1;
          set_error(s,"<format>","Expected \'}\' after \'%c\', got \'%c\'",uVar9,uVar6);
          goto LAB_0003b9de;
        }
        if (uVar6 == 0) {
          iVar1 = -1;
          set_error(s,"<format>","Unexpected end of format string");
          goto LAB_0003b9de;
        }
        if (uVar6 != 0x21 && uVar6 != 0x2a) break;
        if (uVar6 == 0x21) {
          iVar1 = 1;
        }
        else {
          iVar1 = -1;
        }
        next_token(s);
        uVar6 = (uint)(byte)(s->token).token;
        if (uVar6 == 0x7d) goto LAB_0003b9c0;
      }
      if (uVar6 != 0x73) {
        iVar1 = -1;
        set_error(s,"<format>","Expected format \'s\', got \'%c\'");
        goto LAB_0003b9de;
      }
      puVar8 = (undefined4 *)ap->__ap;
      ap->__ap = puVar8 + 1;
      pcVar12 = (char *)*puVar8;
      if (pcVar12 == (char *)0x0) {
        iVar1 = -1;
        set_error(s,"<args>","NULL object key");
        goto LAB_0003b9de;
      }
      next_token(s);
      bVar13 = (s->token).token != '?';
      if (!bVar13) {
        next_token(s);
      }
      if (root == (json_t *)0x0) {
        pjVar2 = (json_t *)0x0;
      }
      else {
        pjVar2 = json_object_get(root,pcVar12);
        if (pjVar2 == (json_t *)0x0 && bVar13) {
          iVar1 = -1;
          set_error(s,"<validation>","Object item not found: %s",pcVar12);
          goto LAB_0003b9de;
        }
      }
      iVar3 = unpack(s,pjVar2,ap);
      if (iVar3 != 0) {
        iVar1 = -1;
        goto LAB_0003b9de;
      }
      pjVar2 = json_null();
      hashtable_set(&key_set,pcVar12,0,pjVar2);
      next_token(s);
    }
LAB_0003b9c0:
    sVar5 = key_set.size;
    if (iVar1 == 0) {
      if ((int)(s->flags << 0x1e) < 0) {
        bVar13 = true;
        goto LAB_0003b9cc;
      }
    }
    else {
      bVar13 = iVar1 == 1;
LAB_0003b9cc:
      if (root == (json_t *)0x0) {
        bVar13 = false;
      }
      if ((bVar13) && (sVar4 = json_object_size(root), sVar5 != sVar4)) {
        iVar1 = -1;
        sVar5 = json_object_size(root);
        set_error(s,"<validation>","%li object item(s) left unpacked",sVar5 - key_set.size);
        goto LAB_0003b9de;
      }
    }
    iVar1 = 0;
LAB_0003b9de:
    hashtable_close(&key_set);
    return iVar1;
  }
  return 0;
}

