//
// Created by kevin on 8/06/22.
//

#ifndef UNTITLED_HEATTRANSFER_H
#define UNTITLED_HEATTRANSFER_H


class HeatConvectionTransfer {
    private:
        const double AIRCONV = 8.7;

    public:
        HeatConvectionTransfer();

        double airHeatTransferRate();

};


#endif //UNTITLED_HEATTRANSFER_H
