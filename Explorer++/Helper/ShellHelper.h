#pragma once

#include <list>

#define CONTROL_PANEL_CATEGORY_VIEW	_T("::{26EE0668-A00A-44D7-9371-BEB064C98683}")

struct JumpListTaskInformation
{
	const TCHAR	*pszName;
	const TCHAR	*pszPath;
	const TCHAR	*pszArguments;
	const TCHAR	*pszIconPath;
	int			iIcon;
};

struct ContextMenuHandler_t
{
	HMODULE		hDLL;
	IUnknown	*pUnknown;
};

void			DecodePath(const TCHAR *szInitialPath,const TCHAR *szCurrentDirectory,TCHAR *szParsingPath,size_t cchDest);
HRESULT			GetIdlFromParsingName(const TCHAR *szParsingName,LPITEMIDLIST *pidl);
HRESULT			GetDisplayName(const TCHAR *szParsingPath,TCHAR *szDisplayName,DWORD uFlags);
HRESULT			GetDisplayName(LPCITEMIDLIST pidlDirectory,TCHAR *szDisplayName,DWORD uFlags);
BOOL			CheckIdl(LPCITEMIDLIST pidl);
BOOL			IsIdlDirectory(LPCITEMIDLIST pidl);
void			GetVirtualFolderParsingPath(UINT uFolderCSIDL,TCHAR *szParsingPath);
HRESULT			GetVirtualParentPath(LPITEMIDLIST pidlDirectory,LPITEMIDLIST *pidlParent);
BOOL			IsNamespaceRoot(LPCITEMIDLIST pidl);
HRESULT			GetCsidlFolderName(UINT csidl,TCHAR *szFolderName,DWORD uParsingFlags);
BOOL			MyExpandEnvironmentStrings(const TCHAR *szSrc,TCHAR *szExpandedPath,DWORD nSize);
HRESULT			BuildHDropList(OUT FORMATETC *pftc,OUT STGMEDIUM *pstg,IN std::list<std::wstring> FilenameList);
HRESULT			BuildShellIDList(OUT FORMATETC *pftc,OUT STGMEDIUM *pstg,IN LPCITEMIDLIST pidlDirectory,IN std::list<LPITEMIDLIST> pidlList);
HRESULT			BindToShellFolder(LPCITEMIDLIST pidlDirectory,IShellFolder **pShellFolder);
BOOL			IsPathGUID(const TCHAR *szPath);
BOOL			CompareIdls(LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
void			SetFORMATETC(FORMATETC *pftc,CLIPFORMAT cfFormat,DVTARGETDEVICE *ptd,DWORD dwAspect,LONG lindex,DWORD tymed);
HRESULT			AddJumpListTasks(const std::list<JumpListTaskInformation> &TaskList);
BOOL			LoadContextMenuHandlers(IN const TCHAR *szRegKey,OUT std::list<ContextMenuHandler_t> *pContextMenuHandlers);
BOOL			LoadIUnknownFromCLSID(IN const TCHAR *szCLSID,OUT ContextMenuHandler_t *pContextMenuHandler);
BOOL			CopyTextToClipboard(const std::wstring &str);
HRESULT			GetItemAttributes(const TCHAR *szItemParsingPath, SFGAOF *pItemAttributes);
HRESULT			GetItemAttributes(LPCITEMIDLIST pidl, SFGAOF *pItemAttributes);
BOOL			ExecuteFileAction(HWND hwnd, const TCHAR *szVerb, const TCHAR *szParameters, const TCHAR *szStartDirectory, LPCITEMIDLIST pidl);
HRESULT			DecodeFriendlyPath(const TCHAR *szFriendlyPath, TCHAR *szParsingPath);

/* Drag and drop helpers. */
DWORD			DetermineCurrentDragEffect(DWORD grfKeyState, DWORD dwCurrentEffect, BOOL bDataAccept, BOOL bOnSameDrive);

/* Default icon indices. */
int				GetDefaultIcon(int iIconType);
int				GetDefaultFolderIconIndex(void);
int				GetDefaultFileIconIndex(void);

/* Infotips. */
HRESULT			GetItemInfoTip(const TCHAR *szItemPath, TCHAR *szInfoTip, size_t cchMax);
HRESULT			GetItemInfoTip(LPCITEMIDLIST pidlComplete, TCHAR *szInfoTip, size_t cchMax);