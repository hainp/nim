/* -*- mode: C; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* vim:set et ts=4: */
/* ibus - The Input Bus
 * Copyright (C) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (C) 2008-2010 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <gtk/gtk.h>
#include <gtk/gtkimmodule.h>

#define IBUS_LOCALDIR ""
static const GtkIMContextInfo nim_im_info = {
    "nim",
    "nim (Intelligent Input Bus)",
    "nim",
    IBUS_LOCALDIR,
    "ja:ko:zh:*"
};

static const GtkIMContextInfo *info_list[] = {
    &nim_im_info
};

G_MODULE_EXPORT const gchar*
g_module_check_init (GModule *module)
{
    return glib_check_version (GLIB_MAJOR_VERSION,
                               GLIB_MINOR_VERSION,
                               0);
}

G_MODULE_EXPORT void
im_module_init (GTypeModule *type_module)
{
    /* make module resident */
    g_type_module_use (type_module);
    g_message("init");
    // ibus_init ();
    // ibus_im_context_register_type (type_module);
}

G_MODULE_EXPORT void
im_module_exit (void)
{
    g_message("exit");
}

G_MODULE_EXPORT GtkIMContext *
im_module_create (const gchar *context_id)
{
    // if (g_strcmp0 (context_id, "ibus") == 0) {
    //     IBusIMContext *context;
    //     context = ibus_im_context_new ();
    //     return (GtkIMContext *) context;
    // }
    g_message("create");
    return NULL;
}

G_MODULE_EXPORT void
im_module_list (const GtkIMContextInfo **contexts[],
                gint                     *n_contexts)
{
    *contexts = info_list;
    *n_contexts = G_N_ELEMENTS (info_list);
    g_message("list");
}
