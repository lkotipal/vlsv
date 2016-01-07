/** This file is part of VLSV file format.
 * 
 *  Copyright 2011-2013,2015 Finnish Meteorological Institute
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef MESH_METADATA_VISIT_UCD_MULTI_H
#define MESH_METADATA_VISIT_UCD_MULTI_H

#include <stdint.h>

#include <mesh_metadata_visit.h>

namespace vlsvplugin {
   
   class VisitUCDMultiMeshMetadata: public VisitMeshMetadata {
    public:
      VisitUCDMultiMeshMetadata();
      virtual ~VisitUCDMultiMeshMetadata();
      
      //uint64_t getBlockSize() const;
      bool getDomainInfo(vlsv::Reader* vlsvReader,int domain,const uint64_t*& domainOffsets,
                         const uint64_t*& ghostOffsets,const uint64_t*& variableOffsets);
      //const uint64_t* getDomainOffsets();
      //const uint64_t* getGhostOffsets();
      //const uint64_t* getVariableOffsets();
      //const std::vector<uint64_t>& getDomainOffsets() const;
      //const std::vector<uint64_t>& getGhostOffsets() const;
      //const std::vector<uint64_t>& getVariableOffsets() const;
      const uint64_t* getMeshBoundingBox();
      //const vlsv::geometry::type& getMeshGeometry() const;
      //uint64_t getNumberOfGhostNodes(uint64_t domain) const;
      //uint64_t getNumberOfGhostZones(uint64_t domain) const;
      //uint64_t getNumberOfLocalNodes(uint64_t domain) const;
      //uint64_t getNumberOfLocalZones(uint64_t domain) const;
      //uint64_t getNumberOfTotalNodes(uint64_t domain) const;
      //uint64_t getNumberOfTotalZones(uint64_t domain) const;      
      bool read(vlsv::Reader* vlsvReader,const std::map<std::string,std::string>& attribs);
      
    protected:

      //bool domainMetadataRead;        /**< If true, domain metadata has been read.*/
      //bool meshMetadataRead;          /**< If true, mesh metadata has been read.*/
      
      //vlsv::geometry::type geometry;  /**< Mesh geometry (Cartesian, Cylindrical, etc.).*/
      //uint64_t blockSize;
      //uint64_t* domainOffsets;
      //uint64_t* ghostOffsets;
      //uint64_t* variableOffsets;
      //uint64_t* meshBoundingBox;

      bool readDomains(vlsv::Reader* vlsvReader);
   };
   
} // namespace vlsvplugin

#endif
