#include "librpc/gen_ndr/ndr_samr.h"
#ifndef __SRV_SAMR__
#define __SRV_SAMR__
NTSTATUS _samr_Connect(pipes_struct *p, struct samr_Connect *r);
NTSTATUS _samr_Close(pipes_struct *p, struct samr_Close *r);
NTSTATUS _samr_SetSecurity(pipes_struct *p, struct samr_SetSecurity *r);
NTSTATUS _samr_QuerySecurity(pipes_struct *p, struct samr_QuerySecurity *r);
NTSTATUS _samr_Shutdown(pipes_struct *p, struct samr_Shutdown *r);
NTSTATUS _samr_LookupDomain(pipes_struct *p, struct samr_LookupDomain *r);
NTSTATUS _samr_EnumDomains(pipes_struct *p, struct samr_EnumDomains *r);
NTSTATUS _samr_OpenDomain(pipes_struct *p, struct samr_OpenDomain *r);
NTSTATUS _samr_QueryDomainInfo(pipes_struct *p, struct samr_QueryDomainInfo *r);
NTSTATUS _samr_SetDomainInfo(pipes_struct *p, struct samr_SetDomainInfo *r);
NTSTATUS _samr_CreateDomainGroup(pipes_struct *p, struct samr_CreateDomainGroup *r);
NTSTATUS _samr_EnumDomainGroups(pipes_struct *p, struct samr_EnumDomainGroups *r);
NTSTATUS _samr_CreateUser(pipes_struct *p, struct samr_CreateUser *r);
NTSTATUS _samr_EnumDomainUsers(pipes_struct *p, struct samr_EnumDomainUsers *r);
NTSTATUS _samr_CreateDomAlias(pipes_struct *p, struct samr_CreateDomAlias *r);
NTSTATUS _samr_EnumDomainAliases(pipes_struct *p, struct samr_EnumDomainAliases *r);
NTSTATUS _samr_GetAliasMembership(pipes_struct *p, struct samr_GetAliasMembership *r);
NTSTATUS _samr_LookupNames(pipes_struct *p, struct samr_LookupNames *r);
NTSTATUS _samr_LookupRids(pipes_struct *p, struct samr_LookupRids *r);
NTSTATUS _samr_OpenGroup(pipes_struct *p, struct samr_OpenGroup *r);
NTSTATUS _samr_QueryGroupInfo(pipes_struct *p, struct samr_QueryGroupInfo *r);
NTSTATUS _samr_SetGroupInfo(pipes_struct *p, struct samr_SetGroupInfo *r);
NTSTATUS _samr_AddGroupMember(pipes_struct *p, struct samr_AddGroupMember *r);
NTSTATUS _samr_DeleteDomainGroup(pipes_struct *p, struct samr_DeleteDomainGroup *r);
NTSTATUS _samr_DeleteGroupMember(pipes_struct *p, struct samr_DeleteGroupMember *r);
NTSTATUS _samr_QueryGroupMember(pipes_struct *p, struct samr_QueryGroupMember *r);
NTSTATUS _samr_SetMemberAttributesOfGroup(pipes_struct *p, struct samr_SetMemberAttributesOfGroup *r);
NTSTATUS _samr_OpenAlias(pipes_struct *p, struct samr_OpenAlias *r);
NTSTATUS _samr_QueryAliasInfo(pipes_struct *p, struct samr_QueryAliasInfo *r);
NTSTATUS _samr_SetAliasInfo(pipes_struct *p, struct samr_SetAliasInfo *r);
NTSTATUS _samr_DeleteDomAlias(pipes_struct *p, struct samr_DeleteDomAlias *r);
NTSTATUS _samr_AddAliasMember(pipes_struct *p, struct samr_AddAliasMember *r);
NTSTATUS _samr_DeleteAliasMember(pipes_struct *p, struct samr_DeleteAliasMember *r);
NTSTATUS _samr_GetMembersInAlias(pipes_struct *p, struct samr_GetMembersInAlias *r);
NTSTATUS _samr_OpenUser(pipes_struct *p, struct samr_OpenUser *r);
NTSTATUS _samr_DeleteUser(pipes_struct *p, struct samr_DeleteUser *r);
NTSTATUS _samr_QueryUserInfo(pipes_struct *p, struct samr_QueryUserInfo *r);
NTSTATUS _samr_SetUserInfo(pipes_struct *p, struct samr_SetUserInfo *r);
NTSTATUS _samr_ChangePasswordUser(pipes_struct *p, struct samr_ChangePasswordUser *r);
NTSTATUS _samr_GetGroupsForUser(pipes_struct *p, struct samr_GetGroupsForUser *r);
NTSTATUS _samr_QueryDisplayInfo(pipes_struct *p, struct samr_QueryDisplayInfo *r);
NTSTATUS _samr_GetDisplayEnumerationIndex(pipes_struct *p, struct samr_GetDisplayEnumerationIndex *r);
NTSTATUS _samr_TestPrivateFunctionsDomain(pipes_struct *p, struct samr_TestPrivateFunctionsDomain *r);
NTSTATUS _samr_TestPrivateFunctionsUser(pipes_struct *p, struct samr_TestPrivateFunctionsUser *r);
NTSTATUS _samr_GetUserPwInfo(pipes_struct *p, struct samr_GetUserPwInfo *r);
NTSTATUS _samr_RemoveMemberFromForeignDomain(pipes_struct *p, struct samr_RemoveMemberFromForeignDomain *r);
NTSTATUS _samr_QueryDomainInfo2(pipes_struct *p, struct samr_QueryDomainInfo2 *r);
NTSTATUS _samr_QueryUserInfo2(pipes_struct *p, struct samr_QueryUserInfo2 *r);
NTSTATUS _samr_QueryDisplayInfo2(pipes_struct *p, struct samr_QueryDisplayInfo2 *r);
NTSTATUS _samr_GetDisplayEnumerationIndex2(pipes_struct *p, struct samr_GetDisplayEnumerationIndex2 *r);
NTSTATUS _samr_CreateUser2(pipes_struct *p, struct samr_CreateUser2 *r);
NTSTATUS _samr_QueryDisplayInfo3(pipes_struct *p, struct samr_QueryDisplayInfo3 *r);
NTSTATUS _samr_AddMultipleMembersToAlias(pipes_struct *p, struct samr_AddMultipleMembersToAlias *r);
NTSTATUS _samr_RemoveMultipleMembersFromAlias(pipes_struct *p, struct samr_RemoveMultipleMembersFromAlias *r);
NTSTATUS _samr_OemChangePasswordUser2(pipes_struct *p, struct samr_OemChangePasswordUser2 *r);
NTSTATUS _samr_ChangePasswordUser2(pipes_struct *p, struct samr_ChangePasswordUser2 *r);
NTSTATUS _samr_GetDomPwInfo(pipes_struct *p, struct samr_GetDomPwInfo *r);
NTSTATUS _samr_Connect2(pipes_struct *p, struct samr_Connect2 *r);
NTSTATUS _samr_SetUserInfo2(pipes_struct *p, struct samr_SetUserInfo2 *r);
NTSTATUS _samr_SetBootKeyInformation(pipes_struct *p, struct samr_SetBootKeyInformation *r);
NTSTATUS _samr_GetBootKeyInformation(pipes_struct *p, struct samr_GetBootKeyInformation *r);
NTSTATUS _samr_Connect3(pipes_struct *p, struct samr_Connect3 *r);
NTSTATUS _samr_Connect4(pipes_struct *p, struct samr_Connect4 *r);
NTSTATUS _samr_ChangePasswordUser3(pipes_struct *p, struct samr_ChangePasswordUser3 *r);
NTSTATUS _samr_Connect5(pipes_struct *p, struct samr_Connect5 *r);
NTSTATUS _samr_RidToSid(pipes_struct *p, struct samr_RidToSid *r);
NTSTATUS _samr_SetDsrmPassword(pipes_struct *p, struct samr_SetDsrmPassword *r);
NTSTATUS _samr_ValidatePassword(pipes_struct *p, struct samr_ValidatePassword *r);
void samr_get_pipe_fns(struct api_struct **fns, int *n_fns);
NTSTATUS rpc_samr_init(void);
#endif /* __SRV_SAMR__ */
