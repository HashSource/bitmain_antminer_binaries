
void EC_GROUP_set_point_conversion_form(EC_GROUP *group,point_conversion_form_t form)

{
  *(point_conversion_form_t *)(group + 0x38) = form;
  return;
}

