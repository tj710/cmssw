///=== This is the Kalman Combinatorial Filter for 4 helix parameters track fit algorithm.
 
#ifndef __KF5PARAMSCOMB__
#define __KF5PARAMSCOMB__
 
#include "L1Trigger/TrackFindingTMTT/interface/L1KalmanComb.h"
#include <TMatrixD.h>
#include "L1Trigger/TrackFindingTMTT/interface/L1track3D.h"

namespace TMTT {

class KF5ParamsComb : public L1KalmanComb{
 
    public:
  enum PAR_IDS { INV2R, PHI0, T, Z0, D0 }; 
	enum MEAS_IDS { PHI, Z };
    public:
        KF5ParamsComb(const Settings* settings, const uint nPar, const string &fitterName );
        virtual ~KF5ParamsComb(){}
        std::string getParams();
 
    protected:
	virtual std::map<std::string, double> getTrackParams(const kalmanState *state )const;
        virtual std::map<std::string, double> getTrackParams_BeamConstr(const kalmanState *state, double& deltaChi2) const;
	virtual std::vector<double> seedx(const L1track3D& l1track3D)const;
	virtual TMatrixD seedP(const L1track3D& l1track3D)const;
	virtual std::vector<double> d(const StubCluster* stubCluster )const;
	virtual TMatrixD H(const StubCluster* stubCluster)const;
	virtual TMatrixD dH(const StubCluster* stubCluster)const;
	virtual TMatrixD F(const StubCluster* stubCluster=0, const kalmanState *state = 0)const;
  	virtual TMatrixD PxxModel( const kalmanState *state, const StubCluster *stubCluster )const; 
	virtual TMatrixD PddMeas(const StubCluster* stubCluster, const kalmanState *state )const;
	virtual bool isGoodState( const kalmanState &state )const;

    private:
	std::vector<double> mapToVec(std::map<std::string, double> x)const;
	std::map<std::string, double> vecToMap(std::vector<double> x)const;
};

}

#endif


