#ifndef BUNDLEINFO_H
#define BUNDLEINFO_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class BundleInfo;
}

class BundleInfo : public QDialog
{
    Q_OBJECT
    
public:
    explicit BundleInfo(QWidget *parent = 0);
    BundleInfo(int b_id, QWidget *parent = 0);
    ~BundleInfo();
    
private:
    Ui::BundleInfo *ui;
    QSqlQueryModel* bundleModel;
    int bundle_id;
    void update_tableBundle_items();
};

#endif // BUNDLEINFO_H
