#include "bundleinfo.h"
#include "ui_bundleinfo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

BundleInfo::BundleInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BundleInfo),
    bundleModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    connect(ui->pushAdd_to_cart, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->pushClose, SIGNAL(clicked()), this, SLOT(reject()));

    ui->tableBundle_items->setModel(bundleModel);
}

BundleInfo::BundleInfo(int b_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BundleInfo),
    bundleModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    connect(ui->pushAdd_to_cart, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->pushClose, SIGNAL(clicked()), this, SLOT(reject()));

    ui->tableBundle_items->setModel(bundleModel);

    bundle_id = b_id;
    update_tableBundle_items();
}

BundleInfo::~BundleInfo()
{
    delete ui;
}

void BundleInfo::update_tableBundle_items()
{
    QSqlDatabase::database().open();
    QSqlQuery query;
    query.prepare("select b.title, author.name, b.isbn "
                  "from book b join bundledbook bb on b.isbn = bb.isbn "
                                "join bundle on bb.bundle_id = bundle.bundle_id "
                                  "join book_s_author ba on b.isbn = ba.isbn "
                                    "join author on author.author_id = ba.author_id "
                  "where bundle.bundle_id = :b_id");
    query.bindValue(":b_id", bundle_id);
    qDebug()<<"update table Bundle items: "<<query.exec();
    qDebug()<<query.lastError();
    bundleModel->setQuery(query);
    bundleModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Title"));
    bundleModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Author"));
    bundleModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
    QSqlDatabase::database().close();
}
