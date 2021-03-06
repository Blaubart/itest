/*******************************************************************
 This file is part of iTest
 Copyright (C) 2005-2009 Michal Tomlein (michal.tomlein@gmail.com)

 iTest is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public Licence
 as published by the Free Software Foundation; either version 2
 of the Licence, or (at your option) any later version.

 iTest is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public Licence for more details.

 You should have received a copy of the GNU General Public Licence
 along with iTest; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
********************************************************************/

#ifndef QUESTION_ITEM_H
#define QUESTION_ITEM_H

#include <QMap>

#include "question.h"

class QuestionItem : public Question
{
public:
    QuestionItem(const QString & = QString());

public slots:
    void shuffleAnswers();
    QList<int> answerOrder();
    Answers answered();
    void setAnswered(Answers);
    double score();
    double maximumScore();
    void addSvgItem(const QString &, const QString &);
    int numSvgItems();
    QString svgName(int);
    QString svg(int);
    static ScoringSystem scoringSystem();
    static void setScoringSystem(ScoringSystem);

private:
    QList<int> q_ans_order;
    Answers q_answer;
    QStringList q_svglist;
    QMap<QString, QString> q_svgmap;
    static ScoringSystem q_scoringsystem;
};

#endif // QUESTION_ITEM_H
