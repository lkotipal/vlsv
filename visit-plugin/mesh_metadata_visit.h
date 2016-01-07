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

//#pragma once

#ifndef MESH_METADATA_VISIT_H
#define MESH_METADATA_VISIT_H

#include <vector>

#include <avtSTMDFileFormat.h>

#include <mesh_vtk.h>
#include <mesh_metadata.h>

namespace vlsvplugin {
   class VisitMeshMetadata: public MeshMetadata {
    public:
      VisitMeshMetadata();
      virtual ~VisitMeshMetadata();
      
      virtual int getBlockOrigin() const;
      virtual uint64_t getBlockSize() const;
      virtual const std::vector<uint64_t>& getDomainOffsets() const;
      virtual const std::vector<uint64_t>& getGhostOffsets() const;
      virtual const std::vector<uint64_t>& getMeshBoundingBox() const;
      virtual uint64_t getNumberOfGhostNodes(uint64_t domain) const;
      virtual uint64_t getNumberOfGhostZones(uint64_t domain) const;
      virtual uint64_t getNumberOfLocalNodes(uint64_t domain) const;
      virtual uint64_t getNumberOfLocalZones(uint64_t domain) const;
      virtual uint64_t getNumberOfTotalNodes(uint64_t domain) const;
      virtual uint64_t getNumberOfTotalZones() const;
      virtual uint64_t getNumberOfTotalZones(uint64_t domain) const;
      virtual const std::vector<uint64_t>& getVariableOffsets() const;
      virtual avtMeshType getMeshType() const;
      virtual std::string getMeshTypeString() const;
      virtual uint64_t getNumberOfDomains() const;
      virtual int getSpatialDimension() const;
      virtual int getTopologicalDimension() const;

      virtual bool read(vlsv::Reader* vlsv,const std::map<std::string,std::string>& attribs);
      
    protected:

      virtual bool readDomainMetadata(vlsv::Reader* vlsvReader);

      int vtkCoordinateDatatype;  /**< VTK datatype that corresponds to the 
				   * datatype of cell coordinates in VLSV file or 
				   * to the datatype generated by MeshReader.*/

      int blockOrigin;
      avtMeshType meshType;       /**< Mesh type, one of AVT_POINT_MESH, ... */
      std::string meshTypeString; /**< String representation of mesh type.*/      
      int spatialDimension;       /**< Spatial dimension of mesh.*/
      int topologicalDimension;   /**< Topological dimension of mesh.*/

      uint64_t blockSize;
      bool domainMetadataRead;                /**< If true, domain metadata has been read.*/
      uint64_t N_domains;                     /**< Number of domains in the mesh.*/
      std::vector<uint64_t> meshBoundingBox;
      std::vector<float> meshCoordinates;

      std::vector<uint64_t> nodeDomainOffsets;
      std::vector<uint64_t> nodeGhostOffsets;
      std::vector<uint64_t> nodeVariableOffsets;

      std::vector<uint64_t> zoneDomainOffsets;
      std::vector<uint64_t> zoneGhostOffsets;
      std::vector<uint64_t> zoneVariableOffsets;      
   };
} // namespace vlsvplugin

#endif
