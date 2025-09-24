
/* WARNING: Unknown calling convention */

void delete_clib_object(clib_object *inObject)

{
  if (inObject == (clib_object *)0x0) {
    return;
  }
  free(inObject->raw_data);
  (*(code *)(undefined *)0x0)(inObject);
  return;
}

