#include "about_widget.h"

AboutWidget::AboutWidget(QString ver, QString qtver, QString year)
{
	setupUi(this);
	QObject::connect(btnClose, SIGNAL(released()), this, SLOT(close()));
	QTimer::singleShot(200, this, SLOT(updateGeometry()));
	QString about = "<p style=\"font-family: sans-serif; font-style:italic;\"><span style=\"font-size:12pt;\">iTest</span><br>";
	about.append("<span style=\"font-size:8pt;\">");
    about.append(tr("Version"));
    about.append(QString(" %1</span></p><p></p>").arg(ver));
	about.append("<p style=\"font-family: sans-serif; font-size:8pt;\">");
    about.append(tr("iTest is a Qt application consisting of a Database Editor and a Test Writer designed for easy computerised examination."));
    about.append("</p><p></p>");
	about.append("<p style=\"font-family: sans-serif; font-size:8pt;\">");
    about.append(tr("This programme is distributed under the terms of the GPL v2."));
	about.append("</p><p></p>");
	about.append(QString("<p style=\"font-family: sans-serif; font-size:8pt;\">2005-%1 <span style=\"font-style:italic;\">Michal Tomlein</span> (michal.tomlein@gmail.com)</p>").arg(year));
	about.append("<p></p><p style=\"font-family: sans-serif; font-size:8pt;\">");
	about.append(tr("The programme is provided AS IS with ABSOLUTELY NO WARRANTY OF ANY KIND, INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE."));
	about.append("</p>");
    aboutTextBrowser->setHtml(about);
	QString aboutQt = "<p style=\"font-family: sans-serif; font-style:italic;\"><span style=\"font-size:12pt;\">";
    aboutQt.append(tr("About Qt"));
	aboutQt.append("</span></p><p></p><p style=\"font-family: sans-serif; font-size:8pt; font-style:italic;\">");
	aboutQt.append(tr("This programme uses Qt Open Source Edition version %1.").arg(qtver));
	aboutQt.append("</p><p></p><p style=\"font-family: sans-serif; font-size:8pt;\">");
	aboutQt.append(tr("Qt is a C++ toolkit for cross-platform application development."));
	aboutQt.append("</p><p></p><p style=\"font-family: sans-serif; font-size:8pt;\">");
	aboutQt.append(tr("Qt provides single-source portability across MS Windows, Mac OS X, Linux and all major commercial Unix variants. Qt is also available for embedded devices as Qtopia Core."));
	aboutQt.append("</p><p></p><p style=\"font-family: sans-serif; font-size:8pt;\">");
	aboutQt.append(tr("Qt is a Trolltech product. See <span style=\"font-style:italic;\">http://www.trolltech.com/qt/</span> for more information."));
	aboutQt.append("</p>");
    aboutQtTextBrowser->setHtml(aboutQt);
}

void AboutWidget::updateGeometry()
{
	gridLayout->setGeometry(0, 0, this->geometry().width(), this->geometry().height());
	if (tabWidget->currentIndex() == 0) {
       aboutGridLayout->setGeometry(0, 0, aboutTab->geometry().width(), aboutTab->geometry().height());
	   aboutQtGridLayout->setGeometry(0, 0, aboutTab->geometry().width(), aboutTab->geometry().height());
    } else if (tabWidget->currentIndex() == 1) {
	   aboutGridLayout->setGeometry(0, 0, aboutQtTab->geometry().width(), aboutQtTab->geometry().height());
	   aboutQtGridLayout->setGeometry(0, 0, aboutQtTab->geometry().width(), aboutQtTab->geometry().height());
    }
}

void AboutWidget::resizeEvent(QResizeEvent *event)
{
	updateGeometry();
	event->accept();
}
