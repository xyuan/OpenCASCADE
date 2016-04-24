// Copyright (c) 2015 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#ifndef _StdLPersistent_TreeNode_HeaderFile
#define _StdLPersistent_TreeNode_HeaderFile

#include <StdObjMgt_Attribute.hxx>

#include <TDataStd_TreeNode.hxx>
#include <Standard_GUID.hxx>


class StdLPersistent_TreeNode
  : public StdObjMgt_Attribute<TDataStd_TreeNode>::Static
{
public:
  //! Read persistent data from a file.
  Standard_EXPORT virtual void Read (StdObjMgt_ReadData& theReadData);

  //! Create an empty transient attribuite
  Standard_EXPORT virtual Handle(TDF_Attribute) CreateAttribute();

  //! Import transient attribuite from the persistent data.
  Standard_EXPORT virtual void ImportAttribute();

private:
  struct dynamic : public Standard_Transient
  {
    Handle(StdLPersistent_TreeNode) First;
    Standard_GUID                   TreeID;
  };

  Handle(dynamic) myDynamicData;
  Handle(StdLPersistent_TreeNode) myNext;
};

#endif