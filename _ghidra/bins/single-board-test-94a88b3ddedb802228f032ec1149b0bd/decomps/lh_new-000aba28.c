
_LHASH * lh_new(LHASH_HASH_FN_TYPE h,LHASH_COMP_FN_TYPE c)

{
  _LHASH *ptr;
  LHASH_NODE **ppLVar1;
  
  ptr = (_LHASH *)CRYPTO_malloc(0x60,"lhash.c",0x78);
  if (ptr != (_LHASH *)0x0) {
    ppLVar1 = (LHASH_NODE **)CRYPTO_malloc(0x40,"lhash.c",0x7a);
    ptr->b = ppLVar1;
    if (ppLVar1 == (LHASH_NODE **)0x0) {
      CRYPTO_free(ptr);
      ptr = (_LHASH *)0x0;
    }
    else {
      *ppLVar1 = (LHASH_NODE *)0x0;
      if (c == (LHASH_COMP_FN_TYPE)0x0) {
        c = strcmp;
      }
      ptr->b[1] = (LHASH_NODE *)0x0;
      if (h == (LHASH_HASH_FN_TYPE)0x0) {
        h = (code *)0xab9e9;
      }
      ptr->b[2] = (LHASH_NODE *)0x0;
      ptr->b[3] = (LHASH_NODE *)0x0;
      ptr->b[4] = (LHASH_NODE *)0x0;
      ptr->b[5] = (LHASH_NODE *)0x0;
      ptr->b[6] = (LHASH_NODE *)0x0;
      ptr->b[7] = (LHASH_NODE *)0x0;
      ptr->b[8] = (LHASH_NODE *)0x0;
      ptr->b[9] = (LHASH_NODE *)0x0;
      ptr->b[10] = (LHASH_NODE *)0x0;
      ptr->b[0xb] = (LHASH_NODE *)0x0;
      ptr->b[0xc] = (LHASH_NODE *)0x0;
      ptr->b[0xd] = (LHASH_NODE *)0x0;
      ptr->b[0xe] = (LHASH_NODE *)0x0;
      ptr->b[0xf] = (LHASH_NODE *)0x0;
      ptr->comp = c;
      ptr->hash = h;
      ptr->num_nodes = 8;
      ptr->p = 0;
      ptr->pmax = 8;
      ptr->num_items = 0;
      ptr->num_expands = 0;
      ptr->num_expand_reallocs = 0;
      ptr->num_contracts = 0;
      ptr->num_contract_reallocs = 0;
      ptr->num_hash_calls = 0;
      ptr->num_comp_calls = 0;
      ptr->num_insert = 0;
      ptr->num_replace = 0;
      ptr->num_delete = 0;
      ptr->num_no_delete = 0;
      ptr->num_retrieve = 0;
      ptr->num_retrieve_miss = 0;
      ptr->num_hash_comps = 0;
      ptr->error = 0;
      ptr->num_alloc_nodes = 0x10;
      ptr->up_load = 0x200;
      ptr->down_load = 0x100;
    }
  }
  return ptr;
}

