/**
 * @file <argos3/plugins/robots/spiri/simulator/spiri_entity.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef SPIRI_ENTITY_H
#define SPIRI_ENTITY_H

namespace argos {
   class CControllableEntity;
   class CEmbodiedEntity;
   class CSpiriEntity;
   class CQuadRotorEntity;
   class CRABEquippedEntity;
}

#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   class CSpiriEntity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

   public:

      CSpiriEntity();

      CSpiriEntity(const std::string& str_id,
                   const std::string& str_controller_id,
                   const CVector3& c_position = CVector3(),
                   const CQuaternion& c_orientation = CQuaternion(),
                   Real f_rab_range = 3.0f,
                   size_t un_rab_data_size = 10);

      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();

      inline CControllableEntity& GetControllableEntity() {
         return *m_pcControllableEntity;
      }

      inline CEmbodiedEntity& GetEmbodiedEntity() {
         return *m_pcEmbodiedEntity;
      }

      inline CQuadRotorEntity& GetQuadRotorEntity() {
         return *m_pcQuadRotorEntity;
      }

      inline CRABEquippedEntity& GetRABEquippedEntity() {
         return *m_pcRABEquippedEntity;
      }

      virtual std::string GetTypeDescription() const {
         return "spiri";
      }

   private:

      CControllableEntity* m_pcControllableEntity;
      CEmbodiedEntity*     m_pcEmbodiedEntity;
      CQuadRotorEntity*    m_pcQuadRotorEntity;
      CRABEquippedEntity*  m_pcRABEquippedEntity;
   };

}

#endif