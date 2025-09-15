
EC_METHOD * EC_GROUP_method_of(EC_GROUP *group)

{
  return *(EC_METHOD **)group;
}

