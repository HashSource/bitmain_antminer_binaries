
BIO * BIO_new(BIO_METHOD *type)

{
  BIO *obj;
  int iVar1;
  
  obj = (BIO *)CRYPTO_malloc(0x40,DAT_000a8c70,0x46);
  if (obj == (BIO *)0x0) {
    ERR_put_error(0x20,0x6c,0x41,DAT_000a8c70,0x48);
  }
  else {
    obj->callback = (_func_745 *)0x0;
    obj->method = type;
    obj->cb_arg = (char *)0x0;
    obj->init = 0;
    obj->flags = 0;
    obj->retry_reason = 0;
    obj->num = 0;
    obj->ptr = (void *)0x0;
    obj->prev_bio = (bio_st *)0x0;
    obj->next_bio = (bio_st *)0x0;
    obj->num_read = 0;
    obj->num_write = 0;
    obj->shutdown = 1;
    obj->references = 1;
    CRYPTO_new_ex_data(0,obj,&obj->ex_data);
    if ((type->create != (_func_742 *)0x0) && (iVar1 = (*type->create)(obj), iVar1 == 0)) {
      CRYPTO_free_ex_data(0,obj,&obj->ex_data);
      CRYPTO_free(obj);
      obj = (BIO *)0x0;
    }
  }
  return obj;
}

