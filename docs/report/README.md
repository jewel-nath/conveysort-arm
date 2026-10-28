# Technical report

**ConveySort-Arm: A Low-Cost Vision-Guided Sorting Cell with a Conveyor Belt
and a Six-Servo Arm — Design and Prototype.** Version 1.0, October 2026.

By Jewel Nath and Shafiul Alam Chowdhury (RoboAI).

[Read the PDF](conveysort-arm-report.pdf) (13 pages, one column). On Zenodo:
[doi:10.5281/zenodo.23741975](https://doi.org/10.5281/zenodo.23741975).

It describes the cell's build, electronics, vision, control and the timing of
a sort, the behaviours recorded on video in November 2024, and the next
steps. Its numbers come from this repository's code; the timing is computed
from the firmware, not measured.

Every diagram is also in [docs/diagrams/](../diagrams/README.md) as its own PDF
and PNG, for reuse.

## Files

| Path | What it is |
|---|---|
| `conveysort-arm-report.tex` | The report |
| `style.tex` | The page layout: one column, 11 pt, coloured headings and summary boxes |
| `figure-style.tex` | Fonts, the colour palette and the TikZ styles every figure shares |
| `references.bib` | The references; every DOI was checked at doi.org |
| `figures/` | One file per diagram (`figNN-*.tex`, TikZ) or plot (`plotNN-*.tex`, pgfplots), each naming the source it was drawn from |
| `make-diagrams.py` | Builds each figure as its own cropped PDF in `docs/diagrams/` |
| `conveysort-arm-report.pdf` | The built report |

The photos come from [docs/media/](../media/). The report and its diagrams
are under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/); the code
keeps its licences (MIT, and Apache 2.0 for the course-derived files).

## Build it

With [Tectonic](https://tectonic-typesetting.github.io), which fetches the
LaTeX packages and the TeX Gyre fonts it needs on the first run:

```bash
cd docs/report
tectonic -X compile conveysort-arm-report.tex
python make-diagrams.py
```

The style uses `fontspec`, so another TeX distribution needs XeLaTeX or
LuaLaTeX (`latexmk -xelatex conveysort-arm-report.tex`).
