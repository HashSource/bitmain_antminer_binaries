
/* WARNING: Unknown calling convention */

int unpack(scanner_t *s,json_t *root,va_list *ap)

{
  int iVar1;
  json_t *value_1;
  json_t *pjVar2;
  json_t *value;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  uint uVar6;
  json_int_t **ppjVar7;
  json_t **target_2;
  uint **ppuVar8;
  int *target_3;
  json_type jVar9;
  double **ppdVar10;
  json_t **ppjVar11;
  undefined4 *puVar12;
  char **ppcVar13;
  undefined4 uVar14;
  double *target;
  json_int_t *pjVar15;
  json_int_t *target_1;
  int *target_4;
  double *pdVar16;
  double *target_5;
  char **target_6;
  char *pcVar17;
  char *key;
  bool bVar18;
  double dVar19;
  json_int_t jVar20;
  hashtable_t key_set;
  
  switch((s->token).token) {
  case 'F':
    if ((root != (json_t *)0x0) && (1 < root->type + ~JSON_STRING)) {
      set_error(s,DAT_0003be90,DAT_0003bed4,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    if ((s->flags & 1) == 0) {
      ppdVar10 = (double **)ap->__ap;
      ap->__ap = ppdVar10 + 1;
      pdVar16 = *ppdVar10;
      if (root != (json_t *)0x0) {
        dVar19 = json_number_value(root);
        *pdVar16 = dVar19;
        return 0;
      }
    }
    break;
  default:
    set_error(s,DAT_0003bc28,DAT_0003bc2c);
    return -1;
  case 'I':
    if ((root != (json_t *)0x0) && (jVar9 = root->type, jVar9 != JSON_INTEGER)) {
LAB_0003bd90:
      set_error(s,DAT_0003be90,DAT_0003beb4,*(undefined4 *)(DAT_0003be8c + jVar9 * 4));
      return -1;
    }
    if ((s->flags & 1) == 0) {
      ppjVar7 = (json_int_t **)ap->__ap;
      ap->__ap = ppjVar7 + 1;
      pjVar15 = *ppjVar7;
      if (root != (json_t *)0x0) {
        jVar20 = json_integer_value(root);
        *pjVar15 = jVar20;
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
      puVar12 = (undefined4 *)ap->__ap;
      ap->__ap = puVar12 + 1;
      ppjVar11 = (json_t **)*puVar12;
    }
    else {
      puVar12 = (undefined4 *)ap->__ap;
      root->refcount = root->refcount + 1;
      ap->__ap = puVar12 + 1;
      ppjVar11 = (json_t **)*puVar12;
    }
    goto LAB_0003bbb8;
  case '[':
    if ((root != (json_t *)0x0) && (root->type != JSON_ARRAY)) {
      set_error(s,DAT_0003be90,DAT_0003bec8,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    iVar1 = 0;
    sVar5 = 0;
    next_token(s);
    while (uVar6 = (uint)(byte)(s->token).token, uVar6 != 0x5d) {
      while( true ) {
        if (iVar1 != 0) {
          set_error(s,DAT_0003be98,DAT_0003be9c);
          return -1;
        }
        if (uVar6 == 0) {
          set_error(s,DAT_0003be98,DAT_0003bea0);
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
      pcVar17 = strchr(DAT_0003bc38,uVar6);
      if (pcVar17 == (char *)0x0) {
        set_error(s,DAT_0003be98,DAT_0003bea8,uVar6);
        return -1;
      }
      if (root == (json_t *)0x0) {
        pjVar2 = (json_t *)0x0;
      }
      else {
        pjVar2 = json_array_get(root,sVar5);
        if (pjVar2 == (json_t *)0x0) {
          set_error(s,DAT_0003be90,DAT_0003beac,sVar5);
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
      bVar18 = true;
    }
    else {
      bVar18 = iVar1 == 1;
    }
    if (root == (json_t *)0x0) {
      bVar18 = false;
    }
    if ((bVar18) && (sVar4 = json_array_size(root), sVar5 != sVar4)) {
      sVar4 = json_array_size(root);
      set_error(s,DAT_0003bc30,DAT_0003bc34,sVar4 - sVar5);
      return -1;
    }
    break;
  case 'b':
    if ((root != (json_t *)0x0) && (1 < root->type + ~JSON_REAL)) {
      set_error(s,DAT_0003be90,DAT_0003becc,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    if ((s->flags & 1) == 0) {
      ppuVar8 = (uint **)ap->__ap;
      ap->__ap = ppuVar8 + 1;
      if (root != (json_t *)0x0) {
        **ppuVar8 = (uint)(root->type == JSON_TRUE);
        return 0;
      }
    }
    break;
  case 'f':
    if ((root != (json_t *)0x0) && (root->type != JSON_REAL)) {
      set_error(s,DAT_0003be90,DAT_0003bedc,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    if ((s->flags & 1) == 0) {
      ppdVar10 = (double **)ap->__ap;
      ap->__ap = ppdVar10 + 1;
      pdVar16 = *ppdVar10;
      if (root != (json_t *)0x0) {
        dVar19 = json_real_value(root);
        *pdVar16 = dVar19;
        return 0;
      }
    }
    break;
  case 'i':
    if ((root != (json_t *)0x0) && (jVar9 = root->type, jVar9 != JSON_INTEGER)) goto LAB_0003bd90;
    if ((s->flags & 1) == 0) {
      puVar12 = (undefined4 *)ap->__ap;
      ap->__ap = puVar12 + 1;
      puVar12 = (undefined4 *)*puVar12;
      if (root != (json_t *)0x0) {
        jVar20 = json_integer_value(root);
        *puVar12 = (int)jVar20;
        return 0;
      }
    }
    break;
  case 'n':
    if ((root != (json_t *)0x0) && (root->type != JSON_NULL)) {
      set_error(s,DAT_0003be90,DAT_0003bed0,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    break;
  case 'o':
    uVar6 = s->flags;
LAB_0003bba8:
    if ((uVar6 & 1) != 0) {
      return 0;
    }
    puVar12 = (undefined4 *)ap->__ap;
    ap->__ap = puVar12 + 1;
    ppjVar11 = (json_t **)*puVar12;
    if (root == (json_t *)0x0) {
      return 0;
    }
LAB_0003bbb8:
    *ppjVar11 = root;
    break;
  case 's':
    if ((root != (json_t *)0x0) && (root->type != JSON_STRING)) {
      set_error(s,DAT_0003be90,DAT_0003bed8,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      return -1;
    }
    if ((s->flags & 1) == 0) {
      puVar12 = (undefined4 *)ap->__ap;
      ap->__ap = puVar12 + 1;
      ppcVar13 = (char **)*puVar12;
      if (ppcVar13 == (char **)0x0) {
        set_error(s,DAT_0003beb8,DAT_0003bee8);
        return -1;
      }
      if (root != (json_t *)0x0) {
        pcVar17 = json_string_value(root);
        *ppcVar13 = pcVar17;
        return 0;
      }
    }
    break;
  case '{':
    iVar1 = hashtable_init(&key_set);
    if (iVar1 != 0) {
      set_error(s,DAT_0003bee0,DAT_0003bee4);
      return -1;
    }
    if ((root != (json_t *)0x0) && (root->type != JSON_OBJECT)) {
      iVar1 = -1;
      set_error(s,DAT_0003be90,DAT_0003be94,*(undefined4 *)(DAT_0003be8c + root->type * 4));
      goto out;
    }
    iVar1 = 0;
    next_token(s);
    while (uVar6 = (uint)(byte)(s->token).token, uVar6 != 0x7d) {
      while( true ) {
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            uVar14 = 0x21;
          }
          else {
            uVar14 = 0x2a;
          }
          iVar1 = -1;
          set_error(s,DAT_0003be98,DAT_0003bea4,uVar14,uVar6);
          goto out;
        }
        if (uVar6 == 0) {
          iVar1 = -1;
          set_error(s,DAT_0003be98,DAT_0003bea0);
          goto out;
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
        set_error(s,DAT_0003be98,DAT_0003beb0);
        goto out;
      }
      ppcVar13 = (char **)ap->__ap;
      ap->__ap = ppcVar13 + 1;
      pcVar17 = *ppcVar13;
      if (pcVar17 == (char *)0x0) {
        iVar1 = -1;
        set_error(s,DAT_0003beb8,DAT_0003bebc);
        goto out;
      }
      next_token(s);
      bVar18 = (s->token).token != '?';
      if (!bVar18) {
        next_token(s);
      }
      if (root == (json_t *)0x0) {
        pjVar2 = (json_t *)0x0;
      }
      else {
        pjVar2 = json_object_get(root,pcVar17);
        if (pjVar2 == (json_t *)0x0 && bVar18) {
          iVar1 = -1;
          set_error(s,DAT_0003be90,DAT_0003bec0,pcVar17);
          goto out;
        }
      }
      iVar3 = unpack(s,pjVar2,ap);
      if (iVar3 != 0) {
        iVar1 = -1;
        goto out;
      }
      pjVar2 = json_null();
      hashtable_set(&key_set,pcVar17,0,pjVar2);
      next_token(s);
    }
LAB_0003b9c0:
    sVar5 = key_set.size;
    if (iVar1 == 0) {
      if ((int)(s->flags << 0x1e) < 0) {
        bVar18 = true;
        goto LAB_0003b9cc;
      }
    }
    else {
      bVar18 = iVar1 == 1;
LAB_0003b9cc:
      if (root == (json_t *)0x0) {
        bVar18 = false;
      }
      if ((bVar18) && (sVar4 = json_object_size(root), sVar5 != sVar4)) {
        iVar1 = -1;
        sVar5 = json_object_size(root);
        set_error(s,DAT_0003be90,DAT_0003bec4,sVar5 - key_set.size);
        goto out;
      }
    }
    iVar1 = 0;
out:
    hashtable_close(&key_set);
    return iVar1;
  }
  return 0;
}

